// FILE HEADER SECTION (MAIN) //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "file.h"
#include "../ui.h"

// Basic Functions //
int id_creator(void)
{
    char check_id[32] = "data/", *temp_id;

    FILE *randTest;
    while(1)
    {
        int rndm_id = 10000000 + rand() %100000000;
        sprintf(temp_id, "%d", rndm_id);
        strcat(check_id, temp_id);
        strcat(check_id, "/log.txt");
        
        if ( (randTest = fopen(check_id, "r") ) != NULL) { fclose(randTest); }
        else { return rndm_id; }
    }
}
// =============== //

// Account Subsystem //
void set_pass(char *temp_id, char *create_pass)
{
    char *create_inside_dir = "data/";

    strcat(create_inside_dir, temp_id);
    strcat(create_inside_dir, "/");
    strcat(create_inside_dir, create_pass);
    strcat(create_inside_dir, ".txt");

    FILE *existPass = fopen(create_inside_dir, "w+");
    fprintf(existPass, "0");
    fclose(existPass);
}

void create_log(char *temp_id) { write_log(temp_id, "Account Created\n"); }

void write_log(char *log_id, char *str_log)
{
    char id_folder[32] = "data/";

    strcat(id_folder, log_id);
    strcat(id_folder, "/log.txt");

    FILE *logId = fopen(id_folder, "a");
    fprintf(logId, "%s", str_log);
    fclose(logId);
}

int check_ban(char *temp_id)
{
    char check_id[32] = "data/", *check_log;
    
    strcat(check_id, temp_id);
    strcat(check_id, "/log.txt");
        
    FILE *checkBan = fopen(check_id, "r");
    do { fscanf(checkBan, "%s", check_log); } while( (feof(checkBan)) != 0);
    fclose(checkBan);

    if ( (strstr(check_log, "BANNED")) != NULL) { return -1; }
    else { return 0; }
}

void fetch_balance(char *id, char *pass)
{
    char *id_folder = "data/", *balance;

    strcat(id_folder, id);
    strcat(id_folder, "/");
    strcat(id_folder, pass);
    strcat(id_folder, ".txt");

    FILE *fetchBal = fopen(id_folder, "r");
    fscanf(fetchBal, "%s", balance);
    fclose(fetchBal);

    printf("%s", balance);
}
// =========== //

// Account System //
void create_account(char *create_pass)
{
    char create_folder[32] = "cd data && mkdir ", *temp_id;
    srand(time(NULL));
    int exist_id = id_creator();
    sprintf(temp_id, "%d", exist_id);

    strcat(create_folder, temp_id);
    system(create_folder);

    set_pass(temp_id, create_pass);
    create_log(temp_id);
    screen(40, temp_id, 4, 0);
}

void delete_account(char *delete_id, char *delete_pass, int as_what)
{
    char *dir_path = "data/";

    strcat(dir_path, delete_id);
    strcat(dir_path, "/");
    strcat(dir_path, delete_pass);
    strcat(dir_path, ".txt");

    if (as_what == 1)
    { 
        remove(dir_path);
        write_log(delete_id, "The Account Has Been Deleted");
    }
    else
    {
        #ifdef _WIN32
            char *id_folder = "cd data && rmdir /s /q ";
        #endif

        #ifdef __linux__
        char *id_folder = "cd data && rm -rf ";
        #endif

        strcat(id_folder, delete_id);
        system(id_folder);
    }
}

void ban_account(char *ban_id) { write_log(ban_id, "|=> ACCOUNT HAS BEEN BANNED <=|"); }
// ============== //

// User System //
void deposit(char *id, char *pass, char *temp_money)
{
    char *open_file = "data/", *bank_money, *temp_bal;
    int temp_int, int_money;

    strcat(open_file, id);
    strcat(open_file, "/");
    strcat(open_file, pass);
    strcat(open_file, ".txt");

    FILE *depFetch = fopen(open_file, "r");
    fscanf(depFetch, "%s", bank_money);
    fclose(depFetch);

    temp_int = atoi(bank_money);
    int_money = atoi(temp_money);
    temp_int += int_money;

    FILE *depWrite = fopen(open_file, "w+");
    fprintf(depWrite, "%d", temp_int);
    fclose(depWrite);

    strcat(temp_money, " Deposited\n");
    write_log(id, temp_money);
}

int withdraw(char *id, char *pass, char *temp_money)
{
    char *open_file = "data/", *bank_money, *temp_bal;
    int temp_int, int_money;

    strcat(open_file, id);
    strcat(open_file, "/");
    strcat(open_file, pass);
    strcat(open_file, ".txt");

    FILE *depFetch = fopen(open_file, "r");
    fscanf(depFetch, "%s", bank_money);
    fclose(depFetch);

    temp_int = atoi(bank_money);
    int_money = atoi(temp_money);

    if ( temp_int < int_money ) { return -1; }
    else { temp_int -= int_money; }

    FILE *depWrite = fopen(open_file, "w+");
    fprintf(depWrite, "%d", temp_int);
    fclose(depWrite);

    strcat(temp_money, " Withdrawn\n");
    write_log(id, temp_money);
}

void change_pass(char *id, char *old_pass, char *new_pass)
{
    char *old_path = "data/" ,new_path[64] = "data/";

    strcat(old_path, id);
    strcat(old_path, "/");
    strcat(old_path, old_pass);
    strcat(old_path, ".txt");

    strcat(new_path, id);
    strcat(new_path, "/");
    strcat(new_path, new_pass);
    strcat(new_path, ".txt");

    rename(old_path, new_path);
}
// =========== //

// MADE BY @hanilr //