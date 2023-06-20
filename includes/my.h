/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** .h
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <fnmatch.h>
#include <ncurses.h>
#include <time.h>
#include <locale.h>
#include "blackjack.h"

typedef struct list_env {
    char *name;
    char *value;
    struct list_env *next;
} list_env_t;

typedef struct path_history {
    char *path;
} path_hist;

typedef struct history {
    char *cmd;
    struct history *next;
} history_t;

typedef struct local_var {
    char *var;
    char *value;
    struct local_var *next;
} local_t;

typedef struct aliases {
    char *alias;
    char *cmd;
    struct aliases *next;
} aliases_t;

typedef struct mysh_s {
    list_env_t *list;
    path_hist *hist;
    history_t *history;
    aliases_t *aliases;
    local_t *local;
} mysh_t;

typedef struct list {
    char *path;
    struct list *next;
} list_t;

int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
char **my_str_to_word_array(char *str, char delim);
void shell(char **env);
int my_cd(char **tab, path_hist **path);
void my_pwd(void);
int my_env(mysh_t *mysh);
char *my_strcat(char *dest, char const *src);
int my_setenv(char **tab, mysh_t *mysh);
int my_strstr(char *str, char const *to_find);
int search(char *str, list_env_t *env_copy);
int my_unsetenv(char **tab, mysh_t *mysh);
char *get_ls_path(list_env_t *list);
void print_list_env(list_env_t *list);
void init_list_env(mysh_t *mysh, char **env);
void add_env(mysh_t *mysh, char *env);
void add_cell(list_env_t **list, char *name, char *value);
char **my_str_tok(char *str, char *delim);
int exec(char **tab, mysh_t *mysh);
path_hist *init_path_hist(void);
int is_letter(char c);
int is_num(char c);
char *my_strdup(char *str);
char *my_strcpy(char *dest, char const *src);
int check_var_name(char *str);
int multicommand(char *line, mysh_t *mysh);
int line_checker(char *line, mysh_t *mysh);
int is_separator(char c);
int check_separators(char *line);
char **exec_tab(char *line);
void add_node(list_t **list, char *path);
list_t *create_list(char **tab);
char **malloc_tab(int len);
int is_redirect(list_t *list);
list_t *redirection(int *in_fd, list_t *list, mysh_t *mysh);
void multi_exec(list_t *list, mysh_t *mysh);
void exec_list(list_t *list, mysh_t *mysh);
int check_exec_list(list_t *list, mysh_t *mysh);
void generic_pipe(list_t *list, mysh_t *mysh);
char *get_path_exec(char **tab, list_env_t *list);
int len_tab(char **tab);
char **tab_fusion(char **tab, char **temp);
char *cut_line(char *line);
void dbl_output_redirect(int *in_fd, char *cmd, mysh_t *mysh, char *file);
void output_redirect(int *in_fd, char *cmd, mysh_t *mysh, char *file);
int is_alphanumeric(char *string);
void display_prompt(void);
list_t *separators(int *in_fd, list_t *list, mysh_t *mysh);
char *get_separator(int i, char *line);
int separator_condition(list_t *list);
int node_is_separator(list_t *list);
void init_sh(mysh_t *mysh, char **env);
int my_putstr(char const *str);
int print_list_alias(aliases_t *alias);
int print_alias(char *index, aliases_t *alias);
aliases_t *return_last_address(aliases_t *alias);
int add_alias(char *alias, char *cmd, aliases_t *aliases, mysh_t *mysh);
aliases_t *return_alias_node(char *alias, aliases_t *aliases);
void expand_glob(char ***args);
int add_history(char *cmd, history_t *history, mysh_t *mysh);
int my_unalias(char **tab, mysh_t *mysh);
char *return_cmd(char **tab);
int my_history(char **tab, mysh_t *mysh);
int error_local_var(char **tab, mysh_t *mysh);
local_t *unset_local_var(mysh_t *mysh, char **tab);
local_t *set_local_var(mysh_t *mysh, char **tab);
void print_list_local(mysh_t *mysh);
void echo_local_var(mysh_t *mysh, char **tab);
char *cp_var(char *var);
int my_alias(char **tab, mysh_t *mysh);
int edit_alias_node(char *alias, char *cmd, aliases_t *aliases, mysh_t *mysh);
void print_error_globbing(char **files);
int is_var_cmd(char **tab, mysh_t *mysh);
int local_variable(mysh_t *mysh, char **tab);
int env_var(char **tab, mysh_t *mysh);
