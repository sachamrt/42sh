/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** local var
*/

#include "../includes/my.h"

void echo_local_var(mysh_t *mysh, char **tab)
{
    local_t *tmp = mysh->local;
    char *var = cp_var(tab[1]);

    while (tmp != NULL) {
        if (strcmp(tmp->var, var) == 0) {
            tmp->value != NULL ? write(1, tmp->value, strlen(tmp->value)) : 0;
            write(1, "\n", 1);
            return;
        }
        tmp = tmp->next;
    }
}

void print_list_local(mysh_t *mysh)
{
    local_t *tmp = mysh->local;

    while (tmp != NULL) {
        write(1, tmp->var, strlen(tmp->var));
        write(1, "\t", 1);
        if (tmp->value != NULL)
            write(1, tmp->value, strlen(tmp->value));
        write(1, "\n", 1);
        tmp = tmp->next;
    }
}
