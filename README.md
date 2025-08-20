# Simple Shell 

This mini shell written in C language simulates the basic behavior of a Unix terminal. Its purpose is to interpret commands entered by the user, search for them in the system, and execute them.

# MAIN FUNCTIONS

- Reads user input 
- Splits the entered line into command and arguments
- Searches the environment variable for directories in $PATH
- Searches for the command within those directories
- Creates a child process and executes the command

# BUILD INS

 "exit": Terminates the shell.
 "env": Prints all environment variables using 'environ'.

# COMPILATION

Compile the program with: gcc -Wall -Werror -Wextra -pedantic main.c main.h function.c -o simpleshell

