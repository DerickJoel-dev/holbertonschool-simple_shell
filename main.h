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

#endif /* MAIN_H */
