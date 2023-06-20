/*
** EPITECH PROJECT, 2023
** 42 sh
** File description:
** condition
*/

#include "../includes/my.h"

int separator_condition(list_t *list)
{
    if (list->next->path[0] == '&' && list->next->path[1] == '&' ||
        list->next->path[0] == '|' && list->next->path[1] == '|')
        return 1;
    return 0;
}

int node_is_separator(list_t *list)
{
    if (list->path[0] == '|' || list->path[0] == '<' ||
        list->path[0] == '>' || list->path[0] == '&')
        return 1;
    return 0;
}
