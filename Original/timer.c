/*

  timer.c firmware for cheap timer using Nitron chip
  MC908QY4CP 16-pin MCU
  compiled with icc08
  
  Time setting is made by 10k POT, the analog input 0-5V.
  Time(mins) = (ADC reading *300)/255
  
  Copyright (c) 2004 Wichit Sirichote

*/
 

#include <io908QY4.H>

#define minute 7200 

// 120 ticks = 1 sec, so 7200 ticks = 1 minute

char count;
char n,timer1;
unsigned int timer2,timer3;
unsigned char sec;
unsigned int min, PV, save_time,set_time;
char x1,x2,x3;
char minute_pass;

void disable_timer()
{
   if(set_time <5) PTA &= ~0x8; // off timer
}

void minute_clock(){
   timer2++;
   if (timer2 > minute)
   {timer2 = 0;
    minute_pass = 1;
    }
}

void run_timer(){
	 
     if (timer3 > 10)
   {
      PTA |= 0x8; // output high relay
      if (minute_pass == 1)
	  {
         minute_pass = 0;
         timer3--;
      }
	  
   }
   else
   {
        PTA &= ~0x8; // off relay
   }

}


char read_ADC()
{
 	 ADSCR = 0; // read channel 0 one time
	 while(!(ADSCR&0x80))
	 ;
	 return ADR;
}
// 3-point moving average (digital filtering)

long read_ADC_filter(){
   PV = read_ADC();
   x3 = x2;
   x2 = x1;
   x1 = PV;
   PV = (x1+x2+x3)/3;
   return PV;
}		 					 

int read_time_dial(){ // from 0min to 300mins (0 to 5Hrs)
  long k;
  k = read_ADC_filter()*300/255;
  return k;
  //   return read_ADC_filter()/2; // for testing
}

// write new set time if out of set_time +-10mins
void write_time(){
	 set_time = read_time_dial();
if(save_time<(set_time-10)||save_time>(set_time+10))
    {save_time = set_time;
     timer3 = save_time; // reload new set time to timer3
     timer2 = 0; // reset minute clock
	}
}
	 
void task_led()
{
 	 if(++timer1>50)
	 {
	 timer1 = 0;
     PTA ^= 0x2; // toggle PA1
	 }
}	 

void main()
{
 	 OCSTRIM = 0x81; // trim internal oscillator
 	 count = n = 0;
 	 TMODH = 0x01;
	 TMODL = 0xf4;
	 TSC = 0x46; // run timer 
	 DDRA = ~0x1; // PA0 is ADC input
	 DDRB = 0xff;
	 PTAPUE = ~0x81; // osc2 pin is PTA4 I/O 
	 ADCLK = 0x40; // ADC clock= fbus/4
		 
	for(;;)
	{
	 while(!(TSC&0x80))
	 ;
	 TSC &= ~0x80; // clear TOF
	// PTA ^= 2; // task running ~60Hz so the loop running is 120Hz or 1/120Hz 
	 task_led();
	 write_time(); 
	 minute_clock();
     disable_timer();
     run_timer();
	 COPCTL = 0; // clear COP 	 
	 }
}	  

