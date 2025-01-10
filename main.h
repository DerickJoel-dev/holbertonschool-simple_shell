#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Function Prototypes */

char **tokenize(char *line);
void execute(char **args);
char *find_in_path(char *command);
int _strncmp(const char *s1, const char *s2, size_t n);

#endif /* MAIN_H */
