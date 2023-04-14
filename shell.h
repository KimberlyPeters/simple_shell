#ifndef _MAIN_H_
#define _MAIN_H_

/* Header Files */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

/* Environmental variables */
extern char **environ;

/* Function declarations (prototypes) for main functions*/
void shell_loop(void);
char *_read_line(void);
char **_split_line(char *line);
int _execute(char **args, char *input);
int _launch(char **args);
void sigint_handler(int sig); 





#endif
