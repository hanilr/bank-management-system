// FILE HEADER SECTION (LINKER) //

#ifndef _SYS_FUNC_H
#define _SYS_FUNC_H

// Basic Functions //
int id_creator(void); // Simple 8 Digits Id Creator
// =============== //

// Account Subsystem //
void set_pass(char *temp_id, char *create_pass); // Create Password Into Id Folder As ".txt"

void create_log(char *temp_id); // Create Log Into Id Folder As ".txt"

void write_log(char *log_id, char *str_log); // Write Logs Into "log.txt"

int check_ban(char *temp_id); // Check User Ban Status In "log.txt"

void fetch_balance(char *id, char *pass); // Fetch User Money In Password ".txt" File
// =========== //

// Account System //
void create_account(char *reate_pass); // Create New Account In "data" Folder

void delete_account(char *delete_id, char *delete_pass, int as_what); // Delete An Account Inside Of "data/<id>"

void ban_account(char *ban_id); // Ban Specific User And Write Inside Of "log.txt"
// ============== //

// User System //
void deposit(char *id, char *pass, char *temp_money); // Deposit Money Into Password ".txt" File

int withdraw(char *id, char *pass, char *temp_money); // Withdraw Money Inside Of Password ".txt" File

void change_pass(char *id, char *old_pass, char *new_pass); // Change Pass Using "rename();" Inside Of "data/<id>"
// =========== //

#endif // MADE BY @hanilr //
