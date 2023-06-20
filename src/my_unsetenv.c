/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_unsetenv
*/

#include "../includes/my.h"

int check_var_name(char *str)
{
    if (is_letter(str[0]) == 0) {
        write(2, "setenv: Variable name must begin with a letter.\n", 48);
        return 0;
    }
    if (my_strlen(str) == 1)
        return 1;
    if (is_alphanumeric(str) == 0) {
        write(2, "setenv: Variable name ", 22);
        write(2, "must contain alphanumeric characters.\n", 39);
        return 0;
    }
    return 1;
}

char *my_strdup(char *str)
{
    char *new = malloc(sizeof(char) * my_strlen(str) + 1);
    int i = 0;

    for (; str[i] != 0; i++)
        new[i] = str[i];
    new[i] = '\0';
    return new;
}

int search(char *str, list_env_t *list)
{
    list_env_t *tmp = list;

    while (tmp != NULL) {
        if (my_strcmp(tmp->name, str) == 0)
            return 1;
        tmp = tmp->next;
    }
    return 0;
}

int len_list(list_env_t *list)
{
    list_env_t *tmp = list;
    int i = 0;

    while (tmp != NULL) {
        i++;
        tmp = tmp->next;
    }
    return i;
}

int my_unsetenv(char **tab, mysh_t *mysh)
{
    list_env_t *tmp = mysh->list;
    int index = search(tab[1], mysh->list);

    if (tab[1] == NULL) {
        write(2, "unsetenv: Too few arguments.\n", 29);
        return 84;
    }
    if (tmp == NULL || index == 0)
        return 0;
    if (my_strcmp(mysh->list->name, tab[1]) == 0) {
        mysh->list = mysh->list->next;
    } else {
        while (my_strcmp(tmp->next->name, tab[1]) != 0)
            tmp = tmp->next;
        if (tmp->next->next != NULL)
            tmp->next = tmp->next->next;
        else
            tmp->next = NULL;
    }
    return 0;
}
