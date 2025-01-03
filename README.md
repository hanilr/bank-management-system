# Bank Management System
Bank management system writtetn in c

* [About The Project](#about-the-project)
* [Compile And Running](#compile-and-running)
* [Usage](#usage)

> [!] This project is finished and no longer take updates.

# About The Project
When I researched about bank management on Github I didn't see a good enough source code written in c and I made this project just to see how well I could do it. The project generally uses 'stdlib.h', 'stdio.h' and 'string.h' libraries in the c language, and the system structure is entirely using file layout. Please indicate in the "issues" section if you encounter any errors or problems.

## Images
The images taken from windows terminal. (OLD)

### ID Entering Screen
![id](https://user-images.githubusercontent.com/77579421/121190327-9dd97300-c873-11eb-85bd-437bf9df8fdf.PNG)

### PASS Entering Screen
![pass](https://user-images.githubusercontent.com/77579421/121190330-9fa33680-c873-11eb-96dd-f2b9f2299243.PNG)

### User Menu
![user_menu](https://user-images.githubusercontent.com/77579421/121190337-a03bcd00-c873-11eb-9dde-57b3440ebb3a.PNG)

### Admin Menu
![control_panel](https://user-images.githubusercontent.com/77579421/121190345-a2059080-c873-11eb-96e0-4a72a67d5a70.PNG)


# Compile And Running

## Compile: ` make `

Deleting all compiled files: ` make clean `

## Run: 

### Windows

For users: ` client.exe ` 

For admins: ` admin.exe `

### Linux: 

For users: ` ./client ` 

For admins: ` ./admin `

# Usage
If you type "create" in id screen then you can create new account. So you will receive your id, so please note it.

Client commands: ` deposit() ` ` withdraw() ` ` change_pass() ` ` delete_account() ` ` create_account() `

Admin commands: ` create_account() ` ` delete_account() ` ` change_password() ` ` ban_account() `
