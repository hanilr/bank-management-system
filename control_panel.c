#include <stdio.h>
#include <string.h>

#include "src/sys_func.h"
#include "src/ui.h"

int main()
{
    char menu_choice[2], temp_str[16], temp_str2[16], temp_str3[16];

    for (;;)
    {
        control_menu(70, 205);
        scanf("%s", menu_choice);

        if (strstr(menu_choice, "q")) { break; }
        else if (strstr(menu_choice, "1"))
        {
            screen(40, 205, "Please enter your password", 13, 16);
            scanf("%s", temp_str);

            if (strstr(temp_str, "q")) {  }
            else { create_account(temp_str); }
        }
        else if (strstr(menu_choice, "2"))
        {
            screen(40, 205, "Enter account id", 8, 16);
            scanf("%s", temp_str);

            screen(40, 205, "Enter password id", 8, 16);
            scanf("%s", temp_str3);

            screen(40, 205, "As admin or user?", 8, 18);
            scanf("%s", temp_str2);

            if (strstr(temp_str, "q")) {  }
            else
            { 
                if (strstr(temp_str2, "user")) { delete_account(temp_str, temp_str3,1); }
                else if (strstr(temp_str2, "admin")) { delete_account(temp_str, temp_str3, 2); }
            }
        }
        else if (strstr(menu_choice, "3"))
        {
            screen(40, 205, "ID", 1, 16);
            scanf("%s", temp_str);

            screen(40, 205, "OLD PASSWORD", 6, 18);
            scanf("%s", temp_str2);

            screen(40, 205, "NEW PASSWORD", 6, 18);
            scanf("%s", temp_str3);
            
            if (strstr(temp_str, "q") || strstr(temp_str2, "q") || strstr(temp_str3, "q")) {  }
            else { change_pass(temp_str, temp_str2, temp_str3); }
        }
        else if (strstr(menu_choice, "4"))
        {
            screen(40, 205, "Enter account id", 13, 16);
            scanf("%s", temp_str);
            
            if (strstr(temp_str, "q")) {  }
            else { ban_account(temp_str); }
        }
    }
    clrscr();

    return 0;
}
