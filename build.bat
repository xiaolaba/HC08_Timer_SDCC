@echo. off

:: timer.c,
:: ref, source code, http://hc08web.de/#examples
:: SDCC manual, http://sdcc.sourceforge.net/doc/sdccman.pdf
:: see page 29, Command line option, select target MCU
:: how to compile

:: xiaolaba, 2019-AUG-31

del *.rst
del *.s19
cls

sdcc -mhc08 --data-loc 0x80 --code-loc 0xEE00 --stack-loc 0xFF timer.c -o qt4_timer.S19
sdcc -mhc08 --data-loc 0x80 --code-loc 0xF800 --stack-loc 0xFF timer.c -o qt2_timer.S19

::goto end

mkdir output
copy *.s19 .\output\
move *.cdb .\output\
move *.lk  .\output\
::move *.lst .\output\
::move *.map .\output\
move *.rel .\output\
::move *.rst .\output\
move *.sym .\output\
move *.asm .\output\

:: clear screen
::cls

@echo.
@echo *.rst is the disassembly code and cpu cycle counter list
@echo *.s19 is the firmware
:end

pause