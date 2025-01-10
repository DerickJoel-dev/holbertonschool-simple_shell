#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>

int main(int ac, char **av, char **env);
char *trim(char *str);
void Tok(char *tokI, char **env);
void exec_com(char *com, char **env);
void free_token(char **tokI, int counter);
void free_paths_array(char **paths, int num_paths);
char *get_path(char *com_name);
void child_creator(char **tokens, char **env);

#endif /* SIMPLE_SHELL_H */
