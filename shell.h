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
void sigint_handler(int signal);

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

int alloc_error2(char *buffer);
int alloc_error1(char *buffer, char *dest_path);


/* Function declarations (prototypes) for built-in functions*/

/**
  * display_help - Help function
  * @arguments: List of arguments passed from parsing.
  * @input: Input line for free.
  * Return: 1 if works.
  */
int display_help(char **arguments, char *input);

/**
  * _env - Env function
  * @arguments: List of arguments passed from parsing.
  * @input: Input line for free.
  * Return: 1 if works.
  */
int _env(char **arguments, char *input);
int _setenv(char *name, char *value);
int _unsetenv(char *name);

char **_check_path(char **args, int *flag);
char *_getenv(const char *var_name);
char **_split_path(char *input_line, char *copy_input_line);
int change_directory(char **arguments, char *input);
int exit_shell(char **arguments, char *input);

/* mem_aux.c */
void _memcpy(void *dest, const void *src, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);

int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *str1, char *str2);
char *_strcpy(char *dest, char *src);
int _strncmp(const char *str1, const char *str2, int n);
void _puts(char *str);
int _putchar(char c);
int _atoi(char *s);

#endif
