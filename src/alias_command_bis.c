/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** 42sh
*/

#include "../includes/my.h"

int print_list_alias(aliases_t *alias)
{
    aliases_t *tmp = alias;

    if (tmp->alias == NULL)
        return 0;

    while (tmp != NULL) {
        my_putstr(tmp->alias);
        my_putstr("\t");
        my_putstr(tmp->cmd);
        my_putstr("\n");
        tmp = tmp->next;
    }
    return 0;
}

int my_unalias_bis(mysh_t *mysh, aliases_t *prev, aliases_t *tmp)
{
    if (prev == NULL)
        mysh->aliases = tmp->next;
    else
        prev->next = tmp->next;
    free(tmp);
    return 0;
}

int my_unalias(char **tab, mysh_t *mysh)
{
    aliases_t *tmp = mysh->aliases;
    aliases_t *prev = NULL;

    if (tab[1] == NULL)
        return my_putstr("unalias: Too few arguments.\n");
    if (tmp->next == NULL) {
        mysh->aliases->alias = NULL;
        mysh->aliases->cmd = NULL;
        return 0;
    }
    if (tmp == NULL)
        return my_putstr("unalias: No aliases to remove.\n");
    while (tmp != NULL) {
        if (my_strcmp(tmp->alias, tab[1]) == 0)
            return my_unalias_bis(mysh, prev, tmp);
        prev = tmp;
        tmp = tmp->next;
    }
    return 0;
}

char *return_cmd(char **tab)
{
    int i = 2;
    int length = 0;
    char *cmd = NULL;

    while (tab[i] != NULL) {
        length += strlen(tab[i]) + 1;
        i++;
    }
    cmd = malloc(length + 1);
    cmd[0] = '\0';
    i = 2;
    while (tab[i] != NULL) {
        strncat(cmd, tab[i], length);
        strncat(cmd, " ", length);
        i++;
    }
    return cmd;
}

int edit_alias_node(char *alias, char *cmd, aliases_t *aliases, mysh_t *mysh)
{
    aliases_t *tmp = aliases;

    while (tmp != NULL) {
        if (my_strcmp(tmp->alias, alias) == 0) {
            tmp->cmd = strdup(cmd);
            return 0;
        }
        tmp = tmp->next;
    }
    return 0;
}
