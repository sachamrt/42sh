/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** 42sh
*/

#include "../includes/my.h"

int print_alias(char *index, aliases_t *alias)
{
    aliases_t *tmp = alias;

    if (tmp->alias == NULL)
        return 0;

    while (tmp != NULL) {
        if (my_strcmp(tmp->alias, index) == 0) {
            my_putstr(tmp->cmd);
            my_putstr("\n");
            return 0;
        }
        tmp = tmp->next;
    }
    return 0;
}

aliases_t *return_last_address(aliases_t *alias)
{
    aliases_t *tmp = alias;

    while (tmp->next != NULL)
        tmp = tmp->next;
    return tmp;
}

int add_alias(char *alias, char *cmd, aliases_t *aliases, mysh_t *mysh)
{
    aliases_t *new = malloc(sizeof(aliases_t));

    new->alias = strdup(alias);
    new->cmd = strdup(cmd);
    new->next = NULL;
    if (aliases->cmd == NULL)
        mysh->aliases = new;
    else
        return_last_address(aliases)->next = new;
    return 0;
}

aliases_t *return_alias_node(char *alias, aliases_t *aliases)
{
    aliases_t *tmp = aliases;

    if (aliases->alias == NULL)
        return NULL;

    while (tmp != NULL) {
        if (my_strcmp(tmp->alias, alias) == 0)
            return tmp;
        tmp = tmp->next;
    }

    return NULL;
}

int my_alias(char **tab, mysh_t *mysh)
{
    char *cmd = NULL;

    if (tab[1] == NULL)
        return print_list_alias(mysh->aliases);
    if (tab[3] == NULL)
        cmd = tab[2];
    else
        cmd = return_cmd(tab);
    if (tab[2] == NULL) {
        if (my_strcmp(tab[1], "alias") == 0)
            return 0;
        return print_alias(tab[1], mysh->aliases);
    }
    if (my_strcmp(tab[2], "alias") == 0)
        return 0;
    if (return_alias_node(tab[1], mysh->aliases) != NULL)
        return edit_alias_node(tab[1], cmd, mysh->aliases, mysh);
    else
        return add_alias(tab[1], cmd, mysh->aliases, mysh);
}
