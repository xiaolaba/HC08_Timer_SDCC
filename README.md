# HC08_Timer_SDCC
The original code by author @ http://www.kswichit.com/hc08fan/hc08fan.html.  
  
My attempts to port to uses SDCC compile

source code has been modified to work with SDCC 3.8.0


```
//#include <io908QY4.H>   // original author was saying, it was used with ICC08  
#include <mc68hc908qy.h>  // include file for SDCC  
```  

```
void main()
{
 	 //OCSTRIM = 0x81; // trim internal oscillator
   OSCTRIM = 0x81; // trim internal oscillator, SDCC 08, Motorola defined name

 	 count = n = 0;
 	 TMODH = 0x01;
	 TMODL = 0xf4;
	 TSC = 0x46; // run timer 

	 //DDRA = ~0x1; // PA0 is ADC input
   DDRA = 0xfe; // PA0 is ADC input, avoid warning of overflow by SDCC

	 DDRB = 0xff;
	 PTAPUE = ~0x81; // osc2 pin is PTA4 I/O 

	 //ADCLK = 0x40; // ADC clock= fbus/4, for ICC 08
   ADICLK = 0x40; // ADC Input Clock Register = fbus/4, SDCC 08, Motorola defined name
```  

