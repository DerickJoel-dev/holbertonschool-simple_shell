#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* Global environment variable */
extern char **environ;

/* Prototypes */
int execute(char *line_input);
char *_trim(char *str);

#endif /* SIMPLE_SHELL_H */

