:loop
del /s /q bin\main.exe
gprbuild -p main.gpr
pause
cd bin
main.exe
cd ..
pause
goto loop