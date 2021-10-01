# ------------------------------- #
# BANK MANAGEMENT SYSTEM MAKEFILE #
# ------------------------------- #

CC= gcc
ui= lib/ui.c
file= lib/sys/file.c

client= src/client.c
admin= src/admin.c

.PHONY: run clean

ifeq ($(OS),Windows_NT)

run: $(admin) $(client) $(file) $(ui)
	$(CC) $(admin) $(file) $(ui) -o admin.exe
	$(CC) $(client) $(file) $(ui) -o client.exe

clean: admin client
	del *.exe

else

run: $(admin) $(client) $(file) $(ui)
	$(CC) $(admin) $(file) $(ui) -o admin
	$(CC) $(client) $(file) $(ui) -o client

clean: admin client
	rm admin client

endif # MADE BY @hanilr #
