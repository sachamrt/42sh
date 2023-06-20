/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** fonctions
*/

#include "../includes/my.h"

int my_env(mysh_t *mysh)
{
    print_list_env(mysh->list);
    return 0;
}

void init_sh(mysh_t *mysh, char **env)
{
    aliases_t *list = malloc(sizeof(aliases_t));
    history_t *hist = malloc(sizeof(history_t));

    list->alias = NULL;
    list->cmd = NULL;
    list->next = NULL;
    mysh->aliases = list;
    hist->cmd = NULL;
    hist->next = NULL;
    mysh->history = hist;
    mysh->local = NULL;
    init_list_env(mysh, env);
}

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return 0;
}
