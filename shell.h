#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <wait.h>
#include <dirent.h>
#include <stdbool.h>
#include <errno.h>

/* Global environemnt */
extern char **environ;

size_t _strlen(const char *str);
char *cmd_read(char *cmd, size_t n, ssize_t value);
char *_strcpy(char *cpy, const char *orignal);
char **split_cmd(char *cmd, size_t n);
char *_strcat(char *dest, const char *src);
char *get_Path(const char *command);
int _strcmp(const char *str1, const char *str2);
char *find_indir(const char *command, const char *directory);
bool isCommandExists(const char *command);
char *_strchr(const char *str, int ch);
char *get_command_directory(const char *command);
char *change_directory_to_command(const char *command);
char *_getenv(const char *name);
char **get_directories_in_path();
char *get_full_path_of_command(const char *command);
void execute_builtin(char **tokens);
void free_tokens(char **tokens);
int is_command_builtin(char *command);
ssize_t display_prompt(void);
int _strncmp(const char *str1, const char *str2, size_t n);
int _unsetenv(const char *cm);
void _setenv(const char *cm, const char *value);
void handel_exit(char **tokens);
void check_command_path(char **tokens);
int handel_cd(char **tokens);
char *_strtok(char s[], const char *d);
ssize_t _getline(char **line, size_t *n, FILE *stream);
void *_realloc(void *ptr, size_t size);
int _getc(FILE *stream);
bool sl_srch(char *str);
void execute_writen_path(char **tokens);
bool sl_srch(char *str);
void execute_writen_path(char **tokens);
void execute_cmd(char **tokens);
void printerror(void);

#endif
