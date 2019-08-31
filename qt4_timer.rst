                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.8.0 #10562 (MINGW64)
                              4 ;--------------------------------------------------------
                              5 	.module timer
                              6 	.optsdcc -mhc08
                              7 	
                              8 	.area HOME    (CODE)
                              9 	.area GSINIT0 (CODE)
                             10 	.area GSINIT  (CODE)
                             11 	.area GSFINAL (CODE)
                             12 	.area CSEG    (CODE)
                             13 	.area XINIT   (CODE)
                             14 	.area CONST   (CODE)
                             15 	.area DSEG    (PAG)
                             16 	.area OSEG    (PAG, OVR)
                             17 	.area XSEG
                             18 	.area XISEG
                             19 	.area	CODEIVT (ABS)
   FFFE                      20 	.org	0xfffe
   FFFE EE 00                21 	.dw	__sdcc_gs_init_startup
                             22 
                             23 	.area GSINIT0
   EE00                      24 __sdcc_gs_init_startup:
   EE00 45 01 00      [ 3]   25 	ldhx	#0x0100
   EE03 94            [ 2]   26 	txs
   EE04 CD F1 6A      [ 5]   27 	jsr	__sdcc_external_startup
   EE07 27 03         [ 3]   28 	beq	__sdcc_init_data
   EE09 CC EE 21      [ 3]   29 	jmp	__sdcc_program_startup
   EE0C                      30 __sdcc_init_data:
                             31 ; _hc08_genXINIT() start
   EE0C 45 00 00      [ 3]   32         ldhx #0
   EE0F                      33 00001$:
   EE0F 65 00 00      [ 3]   34         cphx #l_XINIT
   EE12 27 0A         [ 3]   35         beq  00002$
   EE14 D6 F3 85      [ 4]   36         lda  s_XINIT,x
   EE17 D7 00 EA      [ 4]   37         sta  s_XISEG,x
   EE1A AF 01         [ 2]   38         aix  #1
   EE1C 20 F1         [ 3]   39         bra  00001$
   EE1E                      40 00002$:
                             41 ; _hc08_genXINIT() end
                             42 	.area GSFINAL
   EE1E CC EE 21      [ 3]   43 	jmp	__sdcc_program_startup
                             44 
                             45 	.area CSEG
   EE21                      46 __sdcc_program_startup:
   EE21 CD EF A5      [ 5]   47 	jsr	_main
   EE24 20 FE         [ 3]   48 	bra	.
                             49 ;--------------------------------------------------------
                             50 ; Public variables in this module
                             51 ;--------------------------------------------------------
                             52 	.globl _main
                             53 	.globl _task_led
                             54 	.globl _write_time
                             55 	.globl _read_time_dial
                             56 	.globl _read_ADC_filter
                             57 	.globl _read_ADC
                             58 	.globl _run_timer
                             59 	.globl _minute_clock
                             60 	.globl _disable_timer
                             61 	.globl _minute_pass
                             62 	.globl _x3
                             63 	.globl _x2
                             64 	.globl _x1
                             65 	.globl _set_time
                             66 	.globl _save_time
                             67 	.globl _PV
                             68 	.globl _min
                             69 	.globl _sec
                             70 	.globl _timer3
                             71 	.globl _timer2
                             72 	.globl _timer1
                             73 	.globl _n
                             74 	.globl _count
                             75 	.globl _COPCTL
                             76 	.globl _OSCTRIMVAL
                             77 	.globl _FLBPR
                             78 	.globl _LVISR
                             79 	.globl _BRKSCR
                             80 	.globl _BRK
                             81 	.globl _BRKL
                             82 	.globl _BRKH
                             83 	.globl _FLCR
                             84 	.globl _INT3
                             85 	.globl _INT2
                             86 	.globl _INT1
                             87 	.globl _BFCF
                             88 	.globl _BRKAR
                             89 	.globl _SRSR
                             90 	.globl _BSR
                             91 	.globl _ADICLK
                             92 	.globl _ADR
                             93 	.globl _ADSCR
                             94 	.globl _OSCTRIM
                             95 	.globl _OSCSTAT
                             96 	.globl _TCH1
                             97 	.globl _TCH1L
                             98 	.globl _TCH1H
                             99 	.globl _TSC1
                            100 	.globl _TCH0
                            101 	.globl _TCH0L
                            102 	.globl _TCH0H
                            103 	.globl _TSC0
                            104 	.globl _TMOD
                            105 	.globl _TMODL
                            106 	.globl _TMODH
                            107 	.globl _TCNT
                            108 	.globl _TCNTL
                            109 	.globl _TCNTH
                            110 	.globl _TSC
                            111 	.globl _CONFIG1
                            112 	.globl _CONFIG2
                            113 	.globl _INTSCR
                            114 	.globl _KBIER
                            115 	.globl _KBSCR
                            116 	.globl _PTBPUE
                            117 	.globl _PTAPUE
                            118 	.globl _DDRB
                            119 	.globl _DDRA
                            120 	.globl _PTB
                            121 	.globl _PTA
                            122 ;--------------------------------------------------------
                            123 ; ram data
                            124 ;--------------------------------------------------------
                            125 	.area DSEG    (PAG)
                     0000   126 _PTA	=	0x0000
                     0001   127 _PTB	=	0x0001
                     0004   128 _DDRA	=	0x0004
                     0005   129 _DDRB	=	0x0005
                     000B   130 _PTAPUE	=	0x000b
                     000C   131 _PTBPUE	=	0x000c
                     001A   132 _KBSCR	=	0x001a
                     001B   133 _KBIER	=	0x001b
                     001D   134 _INTSCR	=	0x001d
                     001E   135 _CONFIG2	=	0x001e
                     001F   136 _CONFIG1	=	0x001f
                     0020   137 _TSC	=	0x0020
                     0021   138 _TCNTH	=	0x0021
                     0022   139 _TCNTL	=	0x0022
                     0021   140 _TCNT	=	0x0021
                     0023   141 _TMODH	=	0x0023
                     0024   142 _TMODL	=	0x0024
                     0023   143 _TMOD	=	0x0023
                     0025   144 _TSC0	=	0x0025
                     0026   145 _TCH0H	=	0x0026
                     0027   146 _TCH0L	=	0x0027
                     0026   147 _TCH0	=	0x0026
                     0028   148 _TSC1	=	0x0028
                     0029   149 _TCH1H	=	0x0029
                     002A   150 _TCH1L	=	0x002a
                     0029   151 _TCH1	=	0x0029
                     0036   152 _OSCSTAT	=	0x0036
                     0038   153 _OSCTRIM	=	0x0038
                     003C   154 _ADSCR	=	0x003c
                     003E   155 _ADR	=	0x003e
                     003F   156 _ADICLK	=	0x003f
   0080                     157 _read_ADC_filter_sloc0_1_0:
   0080                     158 	.ds 2
   0082                     159 _read_ADC_filter_sloc1_1_0:
   0082                     160 	.ds 4
   0086                     161 _read_time_dial_sloc0_1_0:
   0086                     162 	.ds 4
   008A                     163 _write_time_sloc0_1_0:
   008A                     164 	.ds 2
   008C                     165 _write_time_sloc1_1_0:
   008C                     166 	.ds 2
                            167 ;--------------------------------------------------------
                            168 ; overlayable items in ram 
                            169 ;--------------------------------------------------------
                            170 ;--------------------------------------------------------
                            171 ; absolute ram data
                            172 ;--------------------------------------------------------
                            173 	.area IABS    (ABS)
                            174 	.area IABS    (ABS)
                            175 ;--------------------------------------------------------
                            176 ; absolute external ram data
                            177 ;--------------------------------------------------------
                            178 	.area XABS    (ABS)
                            179 ;--------------------------------------------------------
                            180 ; external initialized ram data
                            181 ;--------------------------------------------------------
                            182 	.area XISEG
                            183 ;--------------------------------------------------------
                            184 ; extended address mode data
                            185 ;--------------------------------------------------------
                            186 	.area XSEG
                     FE00   187 _BSR	=	0xfe00
                     FE01   188 _SRSR	=	0xfe01
                     FE02   189 _BRKAR	=	0xfe02
                     FE03   190 _BFCF	=	0xfe03
                     FE04   191 _INT1	=	0xfe04
                     FE05   192 _INT2	=	0xfe05
                     FE06   193 _INT3	=	0xfe06
                     FE08   194 _FLCR	=	0xfe08
                     FE09   195 _BRKH	=	0xfe09
                     FE0A   196 _BRKL	=	0xfe0a
                     FE09   197 _BRK	=	0xfe09
                     FE0B   198 _BRKSCR	=	0xfe0b
                     FE0C   199 _LVISR	=	0xfe0c
                     FFBE   200 _FLBPR	=	0xffbe
                     FFC0   201 _OSCTRIMVAL	=	0xffc0
                     FFFF   202 _COPCTL	=	0xffff
   00AD                     203 _count::
   00AD                     204 	.ds 1
   00AE                     205 _n::
   00AE                     206 	.ds 1
   00AF                     207 _timer1::
   00AF                     208 	.ds 1
   00B0                     209 _timer2::
   00B0                     210 	.ds 2
   00B2                     211 _timer3::
   00B2                     212 	.ds 2
   00B4                     213 _sec::
   00B4                     214 	.ds 1
   00B5                     215 _min::
   00B5                     216 	.ds 2
   00B7                     217 _PV::
   00B7                     218 	.ds 2
   00B9                     219 _save_time::
   00B9                     220 	.ds 2
   00BB                     221 _set_time::
   00BB                     222 	.ds 2
   00BD                     223 _x1::
   00BD                     224 	.ds 1
   00BE                     225 _x2::
   00BE                     226 	.ds 1
   00BF                     227 _x3::
   00BF                     228 	.ds 1
   00C0                     229 _minute_pass::
   00C0                     230 	.ds 1
                            231 ;--------------------------------------------------------
                            232 ; global & static initialisations
                            233 ;--------------------------------------------------------
                            234 	.area HOME    (CODE)
                            235 	.area GSINIT  (CODE)
                            236 	.area GSFINAL (CODE)
                            237 	.area GSINIT  (CODE)
                            238 ;--------------------------------------------------------
                            239 ; Home
                            240 ;--------------------------------------------------------
                            241 	.area HOME    (CODE)
                            242 	.area HOME    (CODE)
                            243 ;--------------------------------------------------------
                            244 ; code
                            245 ;--------------------------------------------------------
                            246 	.area CSEG    (CODE)
                            247 ;------------------------------------------------------------
                            248 ;Allocation info for local variables in function 'disable_timer'
                            249 ;------------------------------------------------------------
                            250 ;timer.c:35: void disable_timer()
                            251 ;	-----------------------------------------
                            252 ;	 function disable_timer
                            253 ;	-----------------------------------------
                            254 ;	Register assignment is optimal.
                            255 ;	Stack space usage: 0 bytes.
   EE26                     256 _disable_timer:
                            257 ;timer.c:37: if(set_time <5) PTA &= ~0x8; // off timer
   EE26 C6 00 BC      [ 4]  258 	lda	(_set_time + 1)
   EE29 A0 05         [ 2]  259 	sub	#0x05
   EE2B C6 00 BB      [ 4]  260 	lda	_set_time
   EE2E A2 00         [ 2]  261 	sbc	#0x00
   EE30 24 02         [ 3]  262 	bcc	00103$
   EE32 17 00         [ 4]  263 	bclr	#3,*_PTA
   EE34                     264 00103$:
                            265 ;timer.c:38: }
   EE34 81            [ 4]  266 	rts
                            267 ;------------------------------------------------------------
                            268 ;Allocation info for local variables in function 'minute_clock'
                            269 ;------------------------------------------------------------
                            270 ;timer.c:40: void minute_clock(){
                            271 ;	-----------------------------------------
                            272 ;	 function minute_clock
                            273 ;	-----------------------------------------
                            274 ;	Register assignment is optimal.
                            275 ;	Stack space usage: 0 bytes.
   EE35                     276 _minute_clock:
                            277 ;timer.c:41: timer2++;
   EE35 45 00 B0      [ 3]  278 	ldhx	#_timer2
   EE38 6C 01         [ 4]  279 	inc	1,x
   EE3A 26 01         [ 3]  280 	bne	00110$
   EE3C 7C            [ 3]  281 	inc	,x
   EE3D                     282 00110$:
                            283 ;timer.c:42: if (timer2 > minute)
   EE3D A6 20         [ 2]  284 	lda	#0x20
   EE3F C0 00 B1      [ 4]  285 	sub	(_timer2 + 1)
   EE42 A6 1C         [ 2]  286 	lda	#0x1c
   EE44 C2 00 B0      [ 4]  287 	sbc	_timer2
   EE47 24 0B         [ 3]  288 	bcc	00103$
                            289 ;timer.c:43: {timer2 = 0;
   EE49 4F            [ 1]  290 	clra
   EE4A C7 00 B0      [ 4]  291 	sta	_timer2
   EE4D C7 00 B1      [ 4]  292 	sta	(_timer2 + 1)
                            293 ;timer.c:44: minute_pass = 1;
   EE50 4C            [ 1]  294 	inca
   EE51 C7 00 C0      [ 4]  295 	sta	_minute_pass
   EE54                     296 00103$:
                            297 ;timer.c:46: }
   EE54 81            [ 4]  298 	rts
                            299 ;------------------------------------------------------------
                            300 ;Allocation info for local variables in function 'run_timer'
                            301 ;------------------------------------------------------------
                            302 ;timer.c:48: void run_timer(){
                            303 ;	-----------------------------------------
                            304 ;	 function run_timer
                            305 ;	-----------------------------------------
                            306 ;	Register assignment is optimal.
                            307 ;	Stack space usage: 0 bytes.
   EE55                     308 _run_timer:
                            309 ;timer.c:50: if (timer3 > 10)
   EE55 A6 0A         [ 2]  310 	lda	#0x0a
   EE57 C0 00 B3      [ 4]  311 	sub	(_timer3 + 1)
   EE5A 4F            [ 1]  312 	clra
   EE5B C2 00 B2      [ 4]  313 	sbc	_timer3
   EE5E 24 21         [ 3]  314 	bcc	00104$
                            315 ;timer.c:52: PTA |= 0x8; // output high relay
   EE60 B6 00         [ 3]  316 	lda	*_PTA
   EE62 5F            [ 1]  317 	clrx
   EE63 AA 08         [ 2]  318 	ora	#0x08
   EE65 87            [ 2]  319 	psha
   EE66 86            [ 2]  320 	pula
   EE67 B7 00         [ 3]  321 	sta	*_PTA
                            322 ;timer.c:53: if (minute_pass == 1)
   EE69 C6 00 C0      [ 4]  323 	lda	_minute_pass
   EE6C A1 01         [ 2]  324 	cmp	#0x01
   EE6E 26 13         [ 3]  325 	bne	00106$
                            326 ;timer.c:55: minute_pass = 0;
   EE70 CF 00 C0      [ 4]  327 	stx	_minute_pass
                            328 ;timer.c:56: timer3--;
   EE73 45 00 B2      [ 3]  329 	ldhx	#_timer3
   EE76 E6 01         [ 3]  330 	lda	1,x
   EE78 A0 01         [ 2]  331 	sub	#0x01
   EE7A E7 01         [ 3]  332 	sta	1,x
   EE7C F6            [ 2]  333 	lda	,x
   EE7D A2 00         [ 2]  334 	sbc	#0
   EE7F F7            [ 2]  335 	sta	,x
   EE80 81            [ 4]  336 	rts
   EE81                     337 00104$:
                            338 ;timer.c:62: PTA &= ~0x8; // off relay
   EE81 17 00         [ 4]  339 	bclr	#3,*_PTA
   EE83                     340 00106$:
                            341 ;timer.c:65: }
   EE83 81            [ 4]  342 	rts
                            343 ;------------------------------------------------------------
                            344 ;Allocation info for local variables in function 'read_ADC'
                            345 ;------------------------------------------------------------
                            346 ;timer.c:68: char read_ADC()
                            347 ;	-----------------------------------------
                            348 ;	 function read_ADC
                            349 ;	-----------------------------------------
                            350 ;	Register assignment is optimal.
                            351 ;	Stack space usage: 0 bytes.
   EE84                     352 _read_ADC:
                            353 ;timer.c:70: ADSCR = 0; // read channel 0 one time
   EE84 6E 00 3C      [ 4]  354 	mov	#0x00,*_ADSCR
                            355 ;timer.c:71: while(!(ADSCR&0x80))
   EE87                     356 00101$:
   EE87 B6 3C         [ 3]  357 	lda	*_ADSCR
   EE89 2A FC         [ 3]  358 	bpl     00101$
                            359 ;timer.c:73: return ADR;
   EE8B B6 3E         [ 3]  360 	lda	*_ADR
                            361 ;timer.c:74: }
   EE8D 81            [ 4]  362 	rts
                            363 ;------------------------------------------------------------
                            364 ;Allocation info for local variables in function 'read_ADC_filter'
                            365 ;------------------------------------------------------------
                            366 ;sloc0                     Allocated with name '_read_ADC_filter_sloc0_1_0'
                            367 ;sloc1                     Allocated with name '_read_ADC_filter_sloc1_1_0'
                            368 ;------------------------------------------------------------
                            369 ;timer.c:77: long read_ADC_filter(){
                            370 ;	-----------------------------------------
                            371 ;	 function read_ADC_filter
                            372 ;	-----------------------------------------
                            373 ;	Register assignment is optimal.
                            374 ;	Stack space usage: 0 bytes.
   EE8E                     375 _read_ADC_filter:
                            376 ;timer.c:78: PV = read_ADC();
   EE8E CD EE 84      [ 5]  377 	jsr	_read_ADC
   EE91 97            [ 1]  378 	tax
   EE92 8C            [ 1]  379 	clrh
                            380 ;timer.c:79: x3 = x2;
   EE93 C6 00 BE      [ 4]  381 	lda	_x2
   EE96 C7 00 BF      [ 4]  382 	sta	_x3
                            383 ;timer.c:80: x2 = x1;
   EE99 C6 00 BD      [ 4]  384 	lda	_x1
   EE9C C7 00 BE      [ 4]  385 	sta	_x2
                            386 ;timer.c:81: x1 = PV;
   EE9F CF 00 BD      [ 4]  387 	stx	_x1
                            388 ;timer.c:82: PV = (x1+x2+x3)/3;
   EEA2 BF 81         [ 3]  389 	stx	*(_read_ADC_filter_sloc0_1_0 + 1)
   EEA4 6E 00 80      [ 4]  390 	mov	#0x00,*_read_ADC_filter_sloc0_1_0
   EEA7 C6 00 BE      [ 4]  391 	lda	_x2
   EEAA 5F            [ 1]  392 	clrx
   EEAB BB 81         [ 3]  393 	add	*(_read_ADC_filter_sloc0_1_0 + 1)
   EEAD B7 81         [ 3]  394 	sta	*(_read_ADC_filter_sloc0_1_0 + 1)
   EEAF 9F            [ 1]  395 	txa
   EEB0 B9 80         [ 3]  396 	adc	*_read_ADC_filter_sloc0_1_0
   EEB2 B7 80         [ 3]  397 	sta	*_read_ADC_filter_sloc0_1_0
   EEB4 C6 00 BF      [ 4]  398 	lda	_x3
   EEB7 BB 81         [ 3]  399 	add	*(_read_ADC_filter_sloc0_1_0 + 1)
   EEB9 87            [ 2]  400 	psha
   EEBA 9F            [ 1]  401 	txa
   EEBB B9 80         [ 3]  402 	adc	*_read_ADC_filter_sloc0_1_0
   EEBD 97            [ 1]  403 	tax
   EEBE 4F            [ 1]  404 	clra
   EEBF C7 00 E2      [ 4]  405 	sta	__divsint_PARM_2
   EEC2 A6 03         [ 2]  406 	lda	#0x03
   EEC4 C7 00 E3      [ 4]  407 	sta	(__divsint_PARM_2 + 1)
   EEC7 86            [ 2]  408 	pula
   EEC8 CD F2 B5      [ 5]  409 	jsr	__divsint
   EECB C7 00 B8      [ 4]  410 	sta	(_PV + 1)
   EECE CF 00 B7      [ 4]  411 	stx	_PV
                            412 ;timer.c:83: return PV;
   EED1 C6 00 B8      [ 4]  413 	lda	(_PV + 1)
   EED4 B7 85         [ 3]  414 	sta	*(_read_ADC_filter_sloc1_1_0 + 3)
   EED6 C6 00 B7      [ 4]  415 	lda	_PV
   EED9 B7 84         [ 3]  416 	sta	*(_read_ADC_filter_sloc1_1_0 + 2)
   EEDB 6E 00 83      [ 4]  417 	mov	#0x00,*(_read_ADC_filter_sloc1_1_0 + 1)
   EEDE 6E 00 82      [ 4]  418 	mov	#0x00,*_read_ADC_filter_sloc1_1_0
   EEE1 4E 82 9D      [ 5]  419 	mov	*_read_ADC_filter_sloc1_1_0,*___SDCC_hc08_ret3
   EEE4 4E 83 9C      [ 5]  420 	mov	*(_read_ADC_filter_sloc1_1_0 + 1),*___SDCC_hc08_ret2
   EEE7 BE 84         [ 3]  421 	ldx	*(_read_ADC_filter_sloc1_1_0 + 2)
   EEE9 B6 85         [ 3]  422 	lda	*(_read_ADC_filter_sloc1_1_0 + 3)
                            423 ;timer.c:84: }		 					 
   EEEB 81            [ 4]  424 	rts
                            425 ;------------------------------------------------------------
                            426 ;Allocation info for local variables in function 'read_time_dial'
                            427 ;------------------------------------------------------------
                            428 ;sloc0                     Allocated with name '_read_time_dial_sloc0_1_0'
                            429 ;k                         Allocated with name '_read_time_dial_k_65536_10'
                            430 ;------------------------------------------------------------
                            431 ;timer.c:86: int read_time_dial(){ // from 0min to 300mins (0 to 5Hrs)
                            432 ;	-----------------------------------------
                            433 ;	 function read_time_dial
                            434 ;	-----------------------------------------
                            435 ;	Register assignment is optimal.
                            436 ;	Stack space usage: 0 bytes.
   EEEC                     437 _read_time_dial:
                            438 ;timer.c:88: k = read_ADC_filter()*300/255;
   EEEC CD EE 8E      [ 5]  439 	jsr	_read_ADC_filter
   EEEF C7 00 DD      [ 4]  440 	sta	(__mullong_PARM_2 + 3)
   EEF2 CF 00 DC      [ 4]  441 	stx	(__mullong_PARM_2 + 2)
   EEF5 B6 9C         [ 3]  442 	lda	*___SDCC_hc08_ret2
   EEF7 C7 00 DB      [ 4]  443 	sta	(__mullong_PARM_2 + 1)
   EEFA B6 9D         [ 3]  444 	lda	*___SDCC_hc08_ret3
   EEFC C7 00 DA      [ 4]  445 	sta	__mullong_PARM_2
   EEFF 45 00 D6      [ 3]  446 	ldhx	#__mullong_PARM_1
   EF02 4F            [ 1]  447 	clra
   EF03 F7            [ 2]  448 	sta	,x
   EF04 E7 01         [ 3]  449 	sta	1,x
   EF06 4C            [ 1]  450 	inca
   EF07 E7 02         [ 3]  451 	sta	2,x
   EF09 A6 2C         [ 2]  452 	lda	#0x2c
   EF0B E7 03         [ 3]  453 	sta	3,x
   EF0D CD F1 6C      [ 5]  454 	jsr	__mullong
   EF10 C7 00 C4      [ 4]  455 	sta	(__divslong_PARM_1 + 3)
   EF13 CF 00 C3      [ 4]  456 	stx	(__divslong_PARM_1 + 2)
   EF16 B6 9C         [ 3]  457 	lda	*___SDCC_hc08_ret2
   EF18 C7 00 C2      [ 4]  458 	sta	(__divslong_PARM_1 + 1)
   EF1B B6 9D         [ 3]  459 	lda	*___SDCC_hc08_ret3
   EF1D C7 00 C1      [ 4]  460 	sta	__divslong_PARM_1
   EF20 45 00 C5      [ 3]  461 	ldhx	#__divslong_PARM_2
   EF23 4F            [ 1]  462 	clra
   EF24 F7            [ 2]  463 	sta	,x
   EF25 E7 01         [ 3]  464 	sta	1,x
   EF27 E7 02         [ 3]  465 	sta	2,x
   EF29 4A            [ 1]  466 	deca
   EF2A E7 03         [ 3]  467 	sta	3,x
                            468 ;timer.c:89: return k;
   EF2C CD EF E0      [ 5]  469 	jsr	__divslong
   EF2F B7 89         [ 3]  470 	sta	*(_read_time_dial_sloc0_1_0 + 3)
   EF31 BF 88         [ 3]  471 	stx	*(_read_time_dial_sloc0_1_0 + 2)
   EF33 4E 9C 87      [ 5]  472 	mov	*___SDCC_hc08_ret2,*(_read_time_dial_sloc0_1_0 + 1)
   EF36 4E 9D 86      [ 5]  473 	mov	*___SDCC_hc08_ret3,*_read_time_dial_sloc0_1_0
   EF39 B6 89         [ 3]  474 	lda	*(_read_time_dial_sloc0_1_0 + 3)
   EF3B BE 88         [ 3]  475 	ldx	*(_read_time_dial_sloc0_1_0 + 2)
                            476 ;timer.c:91: }
   EF3D 81            [ 4]  477 	rts
                            478 ;------------------------------------------------------------
                            479 ;Allocation info for local variables in function 'write_time'
                            480 ;------------------------------------------------------------
                            481 ;sloc0                     Allocated with name '_write_time_sloc0_1_0'
                            482 ;sloc1                     Allocated with name '_write_time_sloc1_1_0'
                            483 ;------------------------------------------------------------
                            484 ;timer.c:94: void write_time(){
                            485 ;	-----------------------------------------
                            486 ;	 function write_time
                            487 ;	-----------------------------------------
                            488 ;	Register assignment is optimal.
                            489 ;	Stack space usage: 0 bytes.
   EF3E                     490 _write_time:
                            491 ;timer.c:95: set_time = read_time_dial();
   EF3E CD EE EC      [ 5]  492 	jsr	_read_time_dial
   EF41 B7 8B         [ 3]  493 	sta	*(_write_time_sloc0_1_0 + 1)
   EF43 BF 8A         [ 3]  494 	stx	*_write_time_sloc0_1_0
   EF45 B6 8A         [ 3]  495 	lda	*_write_time_sloc0_1_0
   EF47 C7 00 BB      [ 4]  496 	sta	_set_time
   EF4A B6 8B         [ 3]  497 	lda	*(_write_time_sloc0_1_0 + 1)
   EF4C C7 00 BC      [ 4]  498 	sta	(_set_time + 1)
                            499 ;timer.c:96: if(save_time<(set_time-10)||save_time>(set_time+10))
   EF4F 55 8A         [ 4]  500 	ldhx	*_write_time_sloc0_1_0
   EF51 AF F6         [ 2]  501 	aix	#-10
   EF53 35 8C         [ 4]  502 	sthx	*_write_time_sloc1_1_0
   EF55 C6 00 BA      [ 4]  503 	lda	(_save_time + 1)
   EF58 B0 8D         [ 3]  504 	sub	*(_write_time_sloc1_1_0 + 1)
   EF5A C6 00 B9      [ 4]  505 	lda	_save_time
   EF5D B2 8C         [ 3]  506 	sbc	*_write_time_sloc1_1_0
   EF5F 25 0F         [ 3]  507 	bcs	00101$
   EF61 55 8A         [ 4]  508 	ldhx	*_write_time_sloc0_1_0
   EF63 AF 0A         [ 2]  509 	aix	#10
   EF65 9F            [ 1]  510 	txa
   EF66 C0 00 BA      [ 4]  511 	sub	(_save_time + 1)
   EF69 8B            [ 2]  512 	pshh
   EF6A 86            [ 2]  513 	pula
   EF6B C2 00 B9      [ 4]  514 	sbc	_save_time
   EF6E 24 17         [ 3]  515 	bcc	00104$
   EF70                     516 00101$:
                            517 ;timer.c:97: {save_time = set_time;
   EF70 BE 8A         [ 3]  518 	ldx	*_write_time_sloc0_1_0
   EF72 B6 8B         [ 3]  519 	lda	*(_write_time_sloc0_1_0 + 1)
   EF74 CF 00 B9      [ 4]  520 	stx	_save_time
   EF77 C7 00 BA      [ 4]  521 	sta	(_save_time + 1)
                            522 ;timer.c:98: timer3 = save_time; // reload new set time to timer3
   EF7A CF 00 B2      [ 4]  523 	stx	_timer3
   EF7D C7 00 B3      [ 4]  524 	sta	(_timer3 + 1)
                            525 ;timer.c:99: timer2 = 0; // reset minute clock
   EF80 4F            [ 1]  526 	clra
   EF81 C7 00 B0      [ 4]  527 	sta	_timer2
   EF84 C7 00 B1      [ 4]  528 	sta	(_timer2 + 1)
   EF87                     529 00104$:
                            530 ;timer.c:101: }
   EF87 81            [ 4]  531 	rts
                            532 ;------------------------------------------------------------
                            533 ;Allocation info for local variables in function 'task_led'
                            534 ;------------------------------------------------------------
                            535 ;timer.c:103: void task_led()
                            536 ;	-----------------------------------------
                            537 ;	 function task_led
                            538 ;	-----------------------------------------
                            539 ;	Register assignment is optimal.
                            540 ;	Stack space usage: 0 bytes.
   EF88                     541 _task_led:
                            542 ;timer.c:105: if(++timer1>50)
   EF88 45 00 AF      [ 3]  543 	ldhx	#_timer1
   EF8B 7C            [ 3]  544 	inc	,x
   EF8C C6 00 AF      [ 4]  545 	lda	_timer1
   EF8F A1 32         [ 2]  546 	cmp	#0x32
   EF91 23 11         [ 3]  547 	bls	00103$
                            548 ;timer.c:107: timer1 = 0;
   EF93 4F            [ 1]  549 	clra
   EF94 C7 00 AF      [ 4]  550 	sta	_timer1
                            551 ;timer.c:108: PTA ^= 0x2; // toggle PA1
   EF97 B6 00         [ 3]  552 	lda	*_PTA
   EF99 5F            [ 1]  553 	clrx
   EF9A A8 02         [ 2]  554 	eor	#0x02
   EF9C 87            [ 2]  555 	psha
   EF9D 9F            [ 1]  556 	txa
   EF9E A8 00         [ 2]  557 	eor	#0x00
   EFA0 97            [ 1]  558 	tax
   EFA1 86            [ 2]  559 	pula
   EFA2 B7 00         [ 3]  560 	sta	*_PTA
   EFA4                     561 00103$:
                            562 ;timer.c:110: }	 
   EFA4 81            [ 4]  563 	rts
                            564 ;------------------------------------------------------------
                            565 ;Allocation info for local variables in function 'main'
                            566 ;------------------------------------------------------------
                            567 ;timer.c:112: void main()
                            568 ;	-----------------------------------------
                            569 ;	 function main
                            570 ;	-----------------------------------------
                            571 ;	Register assignment is optimal.
                            572 ;	Stack space usage: 0 bytes.
   EFA5                     573 _main:
                            574 ;timer.c:115: OSCTRIM = 0x81; // trim internal oscillator, SDCC 08, Motorola defined name
   EFA5 6E 81 38      [ 4]  575 	mov	#0x81,*_OSCTRIM
                            576 ;timer.c:117: count = n = 0;
   EFA8 4F            [ 1]  577 	clra
   EFA9 C7 00 AE      [ 4]  578 	sta	_n
   EFAC C7 00 AD      [ 4]  579 	sta	_count
                            580 ;timer.c:118: TMODH = 0x01;
   EFAF 6E 01 23      [ 4]  581 	mov	#0x01,*_TMODH
                            582 ;timer.c:119: TMODL = 0xf4;
   EFB2 6E F4 24      [ 4]  583 	mov	#0xf4,*_TMODL
                            584 ;timer.c:120: TSC = 0x46; // run timer 
   EFB5 6E 46 20      [ 4]  585 	mov	#0x46,*_TSC
                            586 ;timer.c:123: DDRA = 0xfe; // PA0 is ADC input, avoid warning of overflow by SDCC
   EFB8 6E FE 04      [ 4]  587 	mov	#0xfe,*_DDRA
                            588 ;timer.c:125: DDRB = 0xff;
   EFBB 6E FF 05      [ 4]  589 	mov	#0xff,*_DDRB
                            590 ;timer.c:126: PTAPUE = ~0x81; // osc2 pin is PTA4 I/O 
   EFBE 6E 7E 0B      [ 4]  591 	mov	#0x7e,*_PTAPUE
                            592 ;timer.c:129: ADICLK = 0x40; // ADC Input Clock Register = fbus/4, SDCC 08, Motorola defined name
   EFC1 6E 40 3F      [ 4]  593 	mov	#0x40,*_ADICLK
                            594 ;timer.c:133: while(!(TSC&0x80))
   EFC4                     595 00101$:
   EFC4 B6 20         [ 3]  596 	lda	*_TSC
   EFC6 2A FC         [ 3]  597 	bpl     00101$
                            598 ;timer.c:135: TSC &= ~0x80; // clear TOF
   EFC8 1F 20         [ 4]  599 	bclr	#7,*_TSC
                            600 ;timer.c:137: task_led();
   EFCA CD EF 88      [ 5]  601 	jsr	_task_led
                            602 ;timer.c:138: write_time(); 
   EFCD CD EF 3E      [ 5]  603 	jsr	_write_time
                            604 ;timer.c:139: minute_clock();
   EFD0 CD EE 35      [ 5]  605 	jsr	_minute_clock
                            606 ;timer.c:140: disable_timer();
   EFD3 CD EE 26      [ 5]  607 	jsr	_disable_timer
                            608 ;timer.c:141: run_timer();
   EFD6 CD EE 55      [ 5]  609 	jsr	_run_timer
                            610 ;timer.c:142: COPCTL = 0; // clear COP 	 
   EFD9 4F            [ 1]  611 	clra
   EFDA C7 FF FF      [ 4]  612 	sta	_COPCTL
   EFDD 20 E5         [ 3]  613 	bra	00101$
                            614 ;timer.c:144: }	  
   EFDF 81            [ 4]  615 	rts
                            616 	.area CSEG    (CODE)
                            617 	.area CONST   (CODE)
                            618 	.area XINIT   (CODE)
                            619 	.area CABS    (ABS,CODE)
