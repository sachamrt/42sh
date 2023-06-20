/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** set unset
*/

#include "../includes/my.h"


local_t *init_new(char **tab)
{
    local_t *new = malloc(sizeof(local_t));

    new->var = my_strdup(tab[0]);
    if (tab[1] != NULL)
        new->value = strdup(tab[1]);
    else
        new->value = NULL;
    new->next = NULL;
    return new;
}

int sort_condition(char **tab, local_t *tmp)
{
    if (tmp->next == NULL || strcmp(tab[0], tmp->next->var) < 0)
        return 1;
    return 0;
}

local_t *set_local_var(mysh_t *mysh, char **tab)
{
    local_t *tmp = mysh->local;
    char **var_value = my_str_to_word_array(tab[1], '=');
    local_t *new = init_new(var_value);

    if (tmp == NULL)
        return new;
    while (tmp != NULL) {
        if (strcmp(tmp->var , var_value[0]) == 0) {
            tmp->value = var_value[1];
            return mysh->local;
        }
        if (sort_condition(var_value, tmp)) {
            new->next = tmp->next;
            tmp->next = new;
            return mysh->local;
        }
        tmp = tmp->next;
    }
}

local_t *unset_local_var(mysh_t *mysh, char **tab)
{
    local_t *tmp = mysh->local;

    if (tmp == NULL)
        return NULL;
    if (strcmp(tmp->var, tab[1]) == 0)
        return tmp->next;
    while (tmp->next != NULL) {
        if (strcmp(tmp->next->var, tab[1]) == 0)
            tmp->next = tmp->next->next;
        if (tmp->next == NULL)
            break;
        tmp = tmp->next;
    }
    return mysh->local;
}
