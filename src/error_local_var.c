/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** error local var
*/

#include "../includes/my.h"

int error_set(char **tab)
{
    char **var_value = my_str_to_word_array(tab[1], '=');

    if (var_value[0][0] < 'A' || var_value[0][0] > 'Z' &&
    var_value[0][0] < 'a' || var_value[0][0] > 'z') {
        write(1, "set: Variable name must begin with a letter.\n", 45);
        return 1;
    }
    if (var_value[1] == NULL)
        return 0;
    for (int i = 0; var_value[1][i] != '\0'; i++) {
        if ((var_value[1][i] < 'A' || var_value[1][i] > 'Z') &&
        (var_value[1][i] < 'a' || var_value[1][i] > 'z') &&
        (var_value[1][i] < '0' || var_value[1][i] > '9') &&
        var_value[1][i] != '_') {
            write(1, "set: Variable name must contain alphanumeric", 45);
            write(1, " characters.\n", 13);
            return 1;
        }
    }
    return 0;
}

char *cp_var(char *var)
{
    char *new = malloc(sizeof(char) * strlen(var));
    int i = 1;
    int j = 0;

    for (; var[i] != '\0'; i++, j++)
        new[j] = var[i];
    new[j] = '\0';
    return new;
}

int error_echo(char **tab, mysh_t *mysh)
{
    local_t *tmp = mysh->local;
    char *var = cp_var(tab[1]);

    if (tab[1][1] < 'A' || tab[1][1] > 'Z' &&
    tab[1][1] < 'a' || tab[1][1] > 'z') {
        write(1, "Illegal variable name.\n", 23);
        return 1;
    }
    while (tmp) {
        if (strcmp(tmp->var, var) == 0)
            return 0;
        tmp = tmp->next;
    }
    write(1, var, strlen(var));
    write(1, ": Undefined variable.\n", 22);
    return 1;
}

int error_local_var(char **tab, mysh_t *mysh)
{
    if (strcmp(tab[0], "set") == 0 && tab[1] != NULL)
        if (error_set(tab) == 1)
            return 1;
    if (strcmp(tab[0], "unset") == 0 && tab[1] == NULL) {
        write(1, "unset: Too few arguments.\n", 26);
        return 1;
    }
    if (strcmp(tab[0], "echo") == 0)
        return error_echo(tab, mysh);
    return 0;
}
