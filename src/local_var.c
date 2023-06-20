/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** local var
*/

#include "../includes/my.h"

int is_var_cmd(char **tab, mysh_t *mysh)
{
    if (strcmp(tab[0], "set") == 0 ||
    strcmp(tab[0], "unset") == 0)
        return 9;
    if (strcmp(tab[0], "echo") == 0 && tab[1][0] == '$')
        return 9;
    return 0;
}

int local_variable(mysh_t *mysh, char **tab)
{
    if (error_local_var(tab, mysh))
        return 84;
    if (strcmp(tab[0], "set") == 0 && tab[1] == NULL)
        print_list_local(mysh);
    if (strcmp(tab[0], "set") == 0 && tab[1] != NULL)
        mysh->local = set_local_var(mysh, tab);
    if (strcmp(tab[0], "unset") == 0)
        mysh->local = unset_local_var(mysh, tab);
    if (strcmp(tab[0], "echo") == 0)
        echo_local_var(mysh, tab);
    return 0;
}
