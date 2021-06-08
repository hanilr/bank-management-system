#include <stdio.h>
#include <stdlib.h>

#include "sys_func.h"
#include "ui.h"

void clrscr(void)
{
    #ifdef _WIN32
    system("cls");
    #endif

    #ifdef __linux__
    system("clear");
    #endif
}

void new_line(void) { printf("\n"); }

void screen(int len_line, int symbol, char ptext[32], int ptext_len, int wback_len)
{
    clrscr();
    for (int i = 0; i < len_line; i += 1) { printf("%c", symbol); }
    new_line();
    for (int i = 0; i < len_line / 2 - ptext_len; i += 1) { printf(" "); }
    printf(ptext);
    new_line();
    for (int i = 0; i < len_line; i += 1) { printf("%c", symbol); }
    new_line();
    for (int i = 0; i < wback_len - 2; i += 1) { printf(" "); }
    printf("%c ", 175);
}

void menu(char id[16], char pass[8], int len_line, int symbol)
{
    clrscr();
    for (int i = 0; i < len_line; i += 1) { printf("%c", symbol); }
    new_line();
    for (int i = 0; i < len_line/2 - 4; i += 1) { printf(" "); }

    printf("%c ", 175);
    fetch_balance(id, pass);
    printf(" %c", 174);

    new_line();
    for (int i = 0; i < len_line; i += 1) { printf("%c", symbol); }
    new_line();

    printf("1) Deposit");
    for (int i = 0; i < len_line - 28; i += 1) { printf(" "); }
    printf("Change Password (3");
    new_line();

    new_line();
    printf("2) Withdraw");
    for (int i = 0; i < len_line - 28; i += 1) { printf(" "); }
    printf("Delete Account (4");
    new_line();

    new_line();
    printf("Q) Quit");
    new_line();

    for (int i = 0; i < len_line; i += 1) { printf("%c", symbol); }
    new_line();
    printf("| %c ", 175);
}

void control_menu(int len_line, int symbol)
{
    clrscr();
    
    for (int i = 0; i < len_line; i += 1) { printf("%c", symbol); }
    new_line();

    printf("1) Create Account");
    for (int i = 0; i < len_line - 35; i += 1) { printf(" "); }
    printf("Change Password (3");
    new_line();

    new_line();
    printf("2) Delete Account");
    for (int i = 0; i < len_line - 31; i += 1) { printf(" "); }
    printf("Ban Account (4");
    new_line();

    new_line();
    printf("Q) Quit");
    new_line();

    for (int i = 0; i < len_line; i += 1) { printf("%c", symbol); }
    new_line();
    printf("| %c ", 175);
}
