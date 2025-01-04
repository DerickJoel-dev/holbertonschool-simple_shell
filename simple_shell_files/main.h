#ifndef simpleshell
#define simpleshell
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <signal.h>

extern char **environ;

int main(void);
int execute(char *line_input);

char **tokenize(char *line);
char **tokenize_path(char *p);
char *get_path(char *cmd);

void print_env(void);
void free_tokens(char **tokens);
void signal_handler(int signal);

#endif
