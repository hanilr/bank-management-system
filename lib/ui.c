// USER INTERFACE HEADER SECTION (MAIN) //

#include <stdio.h>
#include <stdlib.h>

#include "sys/file.h"
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

void screen(int len_line, char *ptext, int ptext_len, int wback_len)
{
    clrscr();
    for (int i = 0; i < len_line; i += 1) { printf("-"); }
    new_line();
    for (int i = 0; i < len_line / 2 - ptext_len; i += 1) { printf(" "); }
    printf("%s", ptext);
    new_line();
    for (int i = 0; i < len_line; i += 1) { printf("-"); }
    new_line();
    for (int i = 0; i < wback_len - 2; i += 1) { printf(" "); }
    printf("> ");
}

void menu(char *id, char *pass, int len_line)
{
    clrscr();
    for (int i = 0; i < len_line; i += 1) { printf("-"); }
    new_line();
    for (int i = 0; i < len_line/2 - 4; i += 1) { printf(" "); }

    printf("> ");
    fetch_balance(id, pass);
    printf(" <");

    new_line();
    for (int i = 0; i < len_line; i += 1) { printf("-"); }
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

    for (int i = 0; i < len_line; i += 1) { printf("-"); }
    new_line();
    printf("| > ");
}

void control_menu(int len_line)
{
    clrscr();
    
    for (int i = 0; i < len_line; i += 1) { printf("-"); }
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

    for (int i = 0; i < len_line; i += 1) { printf("-"); }
    new_line();
    printf("| > ");
}

// MADE BY @hanilr //