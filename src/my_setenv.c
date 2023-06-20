/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** setenv
*/

#include "../includes/my.h"

list_env_t *push_at_back(list_env_t *list, list_env_t *new)
{
    list_env_t *tmp = list;

    if (list == NULL) {
        return new;
    }
    for (; tmp->next; tmp = tmp->next);
    tmp->next = new;
    return list;
}

list_env_t *create_cell(char *name, char *value)
{
    list_env_t *new = malloc(sizeof(list_env_t));

    new->name = my_strdup(name);
    new->value = my_strdup(value);
    new->next = NULL;
    return new;
}

int len_tab(char **tab)
{
    int i = 0;

    for (; tab[i]; i++);
    return i;
}

int check_overwrite(char **tab)
{
    int len = len_tab(tab);

    if (len < 4)
        return 1;
    if (my_strcmp(tab[3], "1") != 0 && my_strcmp(tab[3], "0") != 0) {
        write(1, "setenv: Too many arguments.\n", 28);
        return -1;
    }
    if (my_strcmp(tab[3], "0") == 0)
        return 0;
    return 1;
}

int my_setenv(char **tab, mysh_t *mysh)
{
    list_env_t *tmp = mysh->list;
    int overwrite = check_overwrite(tab);
    int exist = 0;

    if (overwrite == -1)
        return 84;
    if (tab[1] == NULL) {
        print_list_env(mysh->list);
        return 0;
    } else if (check_var_name(tab[1]) == 0)
        return 84;
    exist = search(tab[1], mysh->list);
    tab[2] == NULL ? tab[2] = "" : 0;
    if (exist == 1 && overwrite == 1) {
        while (my_strcmp(tmp->name, tab[1]) != 0)
            tmp = tmp->next;
        tmp->value = tab[2];
    } else if (exist == 0)
        mysh->list = push_at_back(mysh->list, create_cell(tab[1], tab[2]));
    return 0;
}
