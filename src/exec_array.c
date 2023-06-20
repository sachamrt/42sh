/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** exec tab
*/

#include "../includes/my.h"

char **close_tab(char **list, int j, int k)
{
    if (k != 0) {
        list[j][k] = '\0';
        list[j + 1] = NULL;
    } else
        list[j] = NULL;
    return list;
}

char **exec_tab(char *line)
{
    char **list = malloc_tab(my_strlen(line));
    int j = 0;
    int k = 0;

    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == ';' || line[i] == '|' || line[i] == '>' ||
        line[i] == '<' || line[i] == '&') {
            list[j][k] = '\0';
            j++;
            list[j] = get_separator(i, line);
            strlen(list[j]) == 2 ? i++ : 0;
            k = 0;
            j++;
            continue;
        }
        list[j][k] = line[i];
        k++;
    }
    return close_tab(list, j, k);
}

void exec_list(list_t *list, mysh_t *mysh)
{
    pid_t pid;

    if (check_exec_list(list, mysh) == 1)
        return;
    pid = fork();
    if (pid == 0) {
        generic_pipe(list, mysh);
        exit(0);
    } else
        wait(NULL);
}

void multi_exec(list_t *list, mysh_t *mysh)
{
    list_t *exec = NULL;

    while (list) {
        if (list->path[0] == ';') {
            exec_list(exec, mysh);
            exec = NULL;
        } else
            add_node(&exec, list->path);
        list = list->next;
    }
    exec_list(exec, mysh);
}
