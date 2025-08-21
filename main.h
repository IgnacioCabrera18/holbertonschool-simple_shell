#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>

void build_path(char *dir, char *token, char *dir_tok);
char *_which(char *token);
int tok_line(char *line, char **argv);
void execute(char **argv, char *token);
void print_env(void);
char *get_path_from_env(void);
int exit_and_env(char **argv, char *line);

extern char **environ;

#endif
