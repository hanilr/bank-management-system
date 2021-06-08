#ifndef _SYS_FUNC_H
#define _SYS_FUNC_H

// Basic Functions //
int id_creator(void); // Simple 8 Digits Id Creator
// =============== //

// Account Subsystem //
void set_pass(char temp_id[16], char create_pass[8]); // Create Password Into Id Folder As ".txt"

void create_log(char temp_id[16]); // Create Log Into Id Folder As ".txt"

void write_log(char log_id[16], char str_log[64]); // Write Logs Into "log.txt"

int check_ban(char temp_id[16]); // Check User Ban Status In "log.txt"

void fetch_balance(char id[16], char pass[8]); // Fetch User Money In Password ".txt" File
// =========== //

// Account System //
void create_account(char create_pass[8]); // Create New Account In "data" Folder

void delete_account(char delete_id[16], char delete_pass[8], int as_what); // Delete An Account Inside Of "data/<id>"

void ban_account(char ban_id[16]); // Ban Specific User And Write Inside Of "log.txt"
// ============== //

// User System //
void deposit(char id[16], char pass[8], char temp_money[16]); // Deposit Money Into Password ".txt" File

int withdraw(char id[16], char pass[8], char temp_money[16]); // Withdraw Money Inside Of Password ".txt" File

void change_pass(char id[16], char old_pass[8], char new_pass[8]); // Change Pass Using "rename();" Inside Of "data/<id>"
// =========== //

#endif
