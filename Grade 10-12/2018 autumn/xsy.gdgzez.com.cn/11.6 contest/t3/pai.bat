@echo off
:loop
	gen.exe > in.in
	t3.exe < in.in > my.out
	std.exe < in.in > std.out
	fc my.out std.out
if not errorlevel 1 goto loop
pause
goto loop