/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** exec list
*/

#include "../includes/my.h"

int is_separator(char c)
{
    if (c == ';' || c == '|' || c == '>' || c == '<' || c == '&')
        return 1;
    return 0;
}

int check_separators(char *line)
{
    for (int i = 0; line[i] != '\0'; i++)
        if (is_separator(line[i]))
            return 1;
    return 0;
}

void add_node(list_t **list, char *path)
{
    list_t *tmp = *list;
    list_t *new = malloc(sizeof(list_t));
    new->next = NULL;
    new->path = path;

    if (*list == NULL) {
        *list = new;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
}

list_t *create_list(char **tab)
{
    list_t *list = NULL;

    for (int i = 0; tab[i] != NULL; i++)
        add_node(&list, tab[i]);
    return list;
}
