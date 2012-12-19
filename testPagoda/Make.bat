@echo off
@echo ***************************
@echo **** Start making RGES ****
@echo ***************************
@rem Set path for compiler stuff
call "C:\Program Files\Microsoft Visual Studio 10.0\VC\bin\VCVARS32.BAT"
@rem Call compiler
@echo Compiling ...
nmake /a /f "Rgesmake" > Make.log
set ERR=%errorlevel%
@echo The output can be find in file 'Make.log'
if errorlevel 2 goto err
goto exit

:err
@echo NMAKE ERROR:%ERR%

:exit
@echo ***************************
@echo ****  End making RGES  ****
@echo ***************************
pause
