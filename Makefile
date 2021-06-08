ifeq ($(OS),Windows_NT)

.PHONY: run clear main control_panel

run: 
	gcc main.c src/sys_func.c src/ui.c -o main.exe
	gcc control_panel.c src/sys_func.c src/ui.c -o control_panel.exe

clear:
	del main.exe
	del control_panel.exe

main:
	gcc main.c src/sys_func.c src/ui.c -o main.exe

control_panel:
	gcc control_panel.c src/sys_func.c src/ui.c -o control_panel.exe

else

.PHONY: run clear main control_panel

run: 
	gcc main.c src/sys_func.c src/ui.c -o main
	gcc control_panel.c src/sys_func.c src/ui.c -o control_panel

clear:
	rm main
	rm control_panel

main:
	gcc main.c src/sys_func.c src/ui.c -o main

control_panel:
	gcc control_panel.c src/sys_func.c src/ui.c -o control_panel
	
endif
