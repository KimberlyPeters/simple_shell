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

/* Function declarations (prototypes) for auxiliary funtions */
int alloc_error(char *buffer);
ssize_t _getline(char **line, size_t *n, FILE *stream);
char *realloc_buffer(char *buffer, size_t *bufsize);
int check_alloc(void *ptr);
int _my_getc(void);

int _strcspn(char *str, const char *delimiter);
int _strspn(char *str, const char *delimiter);
char *_strtok_r(char *str, const char *delimiter, char **save_str);
char *_strtok(char *str, const char *delimiter);


	
#endif
