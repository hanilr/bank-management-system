#include <stdio.h>
#include <string.h>

#include "src/sys_func.h"
#include "src/ui.h"

int main()
{
    char id[16], pass[8], menu_choice[2], temp_str[16];

    for(;;)
    {
        // Login Screen //
        screen(40, 205, "ID", 1, 16);
        scanf("%s", id);

        if (strstr(id, "create"))
        {
            screen(40, 205, "Please enter your password", 13, 16);
            scanf("%s", pass);
            create_account(pass);
            return 0;
        }

        screen(40, 205, "PASSWORD", 4, 18);
        scanf("%s", pass);
        // ============ //

        // Ban Check //
        write_log(id, "logged in the account\n");

        if ( check_ban(id) == -1)
        {
            screen(40, 205, "!BANNED ACCOUNT!", 8, 0);
            return -1; 
        }
        else { write_log(id, "checked the account was banned or not\n"); }
        // ========= //

        // Menu Screen //
        for (;;)
        {
            menu(id, pass, 70, 205);
            scanf("%s", menu_choice);

            if (strstr(menu_choice, "q")) { break; }
            else if (strstr(menu_choice, "1"))
            {
                screen(40, 205, "How much to deposit?", 10, 16);
                scanf("%s", temp_str);

                if (strstr(temp_str, "q")) {  }
                else { deposit(id, pass, temp_str); }
            }
            else if (strstr(menu_choice, "2"))
            {
                screen(40, 205, "How much to withdraw?", 10, 16);
                scanf("%s", temp_str);

                if (strstr(temp_str, "q")) {  }
                else { withdraw(id, pass, temp_str); }
            }
            else if (strstr(menu_choice, "3"))
            {
                screen(40, 205, "What is your new password?", 13, 18);
                scanf("%s", temp_str);

                if (strstr(temp_str, "q")) {  }
                else { change_pass(id, pass, temp_str); }
                break;
            }
            else if (strstr(menu_choice, "4"))
            {
                screen(70, 205, "Do you really want to permanently delete your account?", 27, 2);
                scanf("%s", temp_str);

                if (strstr(temp_str, "q")) {  }
                else { delete_account(id, pass, 1); }
                break;
            }
        }
    clrscr();
    // =========== //
    }

    return 0;
}
