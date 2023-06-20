/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** 42sh
*/

#include "../includes/my.h"

int add_history(char *cmd, history_t *history, mysh_t *mysh)
{
    history_t *new = malloc(sizeof(history_t));
    if (new == NULL)
        return 0;

    new->cmd = strdup(cmd);
    new->next = history;
    mysh->history = new;
    return 0;
}

int my_history(char **tab, mysh_t *mysh)
{
    history_t *tmp = mysh->history;

    if (my_strlen(tab[0]) == 1)
        return my_putstr("!: Command not found.\n");
    else
        ++tab[0];

    if (tmp->cmd == NULL)
        return 0;
    while (tmp->cmd != NULL) {
        if (strncmp(tmp->cmd, tab[0], strlen(tab[0])) == 0) {
            line_checker(tmp->cmd, mysh);
            return 0;
        }
        tmp = tmp->next;
    }
    my_putstr(tab[0]);
    my_putstr(": Event not found.\n");
    return 0;
}
