/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** list
*/

#include "../includes/my.h"

void print_list_env(list_env_t *list)
{
    list_env_t *tmp = list;

    while (tmp) {
        write(1, tmp->name, my_strlen(tmp->name));
        write(1, "=", 1);
        write(1, tmp->value, my_strlen(tmp->value));
        write(1, "\n", 1);
        tmp = tmp->next;
    }
}

char **split_var_value(char *str)
{
    char **tab = malloc(sizeof(char *) * 2);
    int i = 0;
    int j = 0;

    for (int l = 0; l < 2; l++)
        tab[l] = malloc(sizeof(char) * my_strlen(str));
    for (; str[i] != '='; i++)
        tab[0][i] = str[i];
    tab[0][i] = '\0';
    i++;
    for (; str[i] != '\0'; i++, j++)
        tab[1][j] = str[i];
    tab[1][j] = '\0';
    return tab;
}

void add_env(mysh_t *mysh, char *env)
{
    list_env_t *tmp = mysh->list;
    list_env_t *new = malloc(sizeof(list_env_t));
    char **tab = split_var_value(env);

    new->name = tab[0];
    new->value = tab[1];
    new->next = NULL;

    if (tmp == NULL)
        mysh->list = new;
    else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new;
    }
}

void init_list_env(mysh_t *mysh, char **env)
{
    mysh->list = NULL;
    mysh->hist = init_path_hist();

    if (env == NULL)
        return;
    for (int i = 0; env[i] != NULL; i++)
        add_env(mysh, env[i]);
}

path_hist *init_path_hist(void)
{
    path_hist *path = malloc(sizeof(path_hist));
    char *tmp = malloc(sizeof(char) * 1000);

    getcwd(tmp, 1000);
    path->path = tmp;
    return path;
}
