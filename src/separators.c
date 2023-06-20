/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** separators
*/

#include "../includes/my.h"

char *get_separator_bis(int i, char *line)
{
    char *separator;
    return NULL;
}

char *fill_separator(char c, int size)
{
    char *separator = malloc(sizeof(char) * 3);

    if (size == 2) {
        separator[0] = c;
        separator[1] = c;
        separator[2] = '\0';
    } else {
        separator[0] = c;
        separator[1] = '\0';
    }
    return separator;
}

char *get_separator(int i, char *line)
{
    if (line[i] == '>' && line[i + 1] == '>')
        return fill_separator('>', 2);
    if (line[i] == '<' && line[i + 1] == '<')
        return fill_separator('<', 2);
    if (line[i] == '|' && line[i + 1] == '|')
        return fill_separator('|', 2);
    if (line[i] == '&' && line[i + 1] == '&')
        return fill_separator('&', 2);
    return fill_separator(line[i], 1);
}

list_t *separators(int *in_fd, list_t *list, mysh_t *mysh)
{
    dup2(*in_fd, STDIN_FILENO);
    int prev_ret;
    int type;

    for (;list->next->path[0] == '|' ||
    list->next->path[0] == '&'; list = list->next->next) {
        if (list->next->path[0] == '&' && list->next->path[1] == '&')
            type = 0;
        else
            type = 1;
        if (type == 0 && prev_ret > 0)
            continue;
        if (type == 0 && prev_ret == 0)
            prev_ret = line_checker(list->next->next->path, mysh);
        if (type == 1 && prev_ret == 0)
            continue;
        if (type == 1 && prev_ret > 0)
            prev_ret = line_checker(list->next->next->path, mysh);
    }
    return list;
}
