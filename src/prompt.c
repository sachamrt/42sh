/*
** EPITECH PROJECT, 2023
** 4sh
** File description:
** display prompt
*/

#include "../includes/my.h"

void display_prompt(void)
{
    char *here = malloc(sizeof(char *) * 10000);

    getcwd(here, 10000);
    write(1,here ,my_strlen(here));
    write(1, "$> ", 3);
    free(here);
}

int env_var(char **tab, mysh_t *mysh)
{
    if (strcmp(tab[0], "setenv") == 0)
        return my_setenv(tab, mysh);
    if (strcmp(tab[0], "unsetenv") == 0)
        return my_unsetenv(tab, mysh);
}
