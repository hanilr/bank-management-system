// USER INTERFACE HEADER SECTION (LINKER) //

#ifndef _UI_H
#define _UI_H

void clrscr(void); // Clear Screen

void new_line(void); // New Line Using "printf();" (SHORTCUT)

void screen(int len_line, char *ptext, int ptext_len, int wback_len); // Question Or Warning Screen

void menu(char *id, char *pass, int len_line); // Menu Screen For Users

void control_menu(int len_line); // Menu Screen For Admins

#endif // MADE BY @hanilr //
