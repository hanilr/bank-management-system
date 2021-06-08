#ifndef _UI_H
#define _UI_H

void clrscr(void); // Clear Screen

void new_line(void); // New Line Using "printf();" (SHORTCUT)

void screen(int len_line, int symbol, char ptext[32], int ptext_len, int wback_len); // Question Or Warning Screen

void menu(char id[16], char pass[8], int len_line, int symbol); // Menu Screen For Users

void control_menu(int len_line, int symbol); // Menu Screen For Admins

#endif