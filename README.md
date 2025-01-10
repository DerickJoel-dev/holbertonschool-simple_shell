# Simple Shell

The shell is like a program that recieves command inputs from the user's keyboard and sends them to a machine to be executed by the kernel.

it also checks to see if the user's command inputs are correct.

- Initialize: In this stage, a typical shell will read as well as execute its set of configuration files. These alter the shell's behavior.

- Interpret: The shell then reads command from "stdin" and executes them.

- Terminate: After the execution of its commands, the shell performs any of the shutdown commands, frees any memory, and terminates.

These stages are general and they may be applicable to a wide range of programs, but we will use them as the fundation for our shell.

Our shell will be so basic that there will be no configuration files and no shutdown command.

## Prototype
int main(void);
## Compilation
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

## Prerequisites
Before you can run **simplehsell**, make sure you have the following:

- A Unix-like operating system (Linux, macOS, etc.)
- GCC (GNU Compiler Collection) installed for compilation.
## Testing
Our shell work like this in interactive mode:

simpleshell$ ./hsh

simpleshell$ /bin/ls
  hsh main.c shell.c

simpleshell$ **exit**

---
Also in non-interactive mode:

simpleshell$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
simpleshell$

simpleshell$ cat test_ls_2
/bin/ls
/bin/ls
simpleshell$

simpleshell$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
simpleshell$


## Files
- AUTHORS: contributors to the project.
 - execute.c: execute a command.
 - free_token.c: frees the array of tokens.
 - main.h: header file.
 - path.c: functions related to path.
 - tokenize.c: tokenize input.
 - process_command.c: path related.
 - process_interactive.c: handles the interactive mode of the shell.
 -  process_non_interactive.c: handles the non-interactive mode of the shell.
 - path_helpers.c: path related.
 - execution_helpers.c: handle fork and execute command.
 - clean_helpers.c: removes surrounding quotes from input.
 - special_command.c: handles exit and env.
## Functions
  - exit
   - execve
   - fork
   - free
   - getenv
   - getline
   - isatty
   - malloc
   - perror
   - printf
   - sprintf
   - stat
   - strcmp
   - strdup
   - strtok
   - wait
## Conclusion
This is a basic Unix-like shell program called **simpleshell**. It provides a simple command-line interface for executing commands and displaying environment variables. Building a simple shell in C involves understanding how to parse and execute commands, handle user input and output, and manage processes using system calls like fork and execve. The process of creating a shell requires a deep understanding of C programming language and the Unix operating system.

