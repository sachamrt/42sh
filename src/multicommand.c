/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** multicommand
*/

#include "../includes/my.h"

void piping(int *in_fd, char *path, mysh_t *mysh)
{
    int fd[2];
    pipe(fd);
    pid_t pid = fork();

    if (pid == 0) {
        dup2(*in_fd, STDIN_FILENO);
        close(*in_fd);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        exit(line_checker(path, mysh));
    } else {
        close(*in_fd);
        *in_fd = fd[0];
        close(fd[1]);
    }
}

void generic_pipe(list_t *list, mysh_t *mysh)
{
    int in_fd = dup(STDIN_FILENO);

    for (;list && list->next; list = list->next) {
        if (node_is_separator(list) == 1)
            continue;
        if (list->next->path[0] == '>' || list->next->path[0] == '<') {
            list = redirection(&in_fd, list, mysh);
            continue;
        }
        if (separator_condition(list) == 1) {
            list = separators(&in_fd, list, mysh);
            continue;
        }
        piping(&in_fd, list->path, mysh);
    }
    if (list != NULL) {
        dup2(in_fd, STDIN_FILENO);
        close(in_fd);
        line_checker(list->path, mysh);
    }
}

int check_next(list_t *list)
{
    if (list->next == NULL)
        return 1;
    for (int i = 0; list->next->path[i]; i++) {
        if (list->next->path[i] != ' ')
            return 0;
    }
    return 1;
}

int check_exec_list(list_t *list, mysh_t *mysh)
{
    list_t *tmp = list;

    while (tmp) {
        if (tmp->path[0] == '|' && tmp->path[1] == '\0' && check_next(tmp)) {
            write(2, "Invalid null command.\n", 22);
            return 1;
        }
        if ((tmp->path[0] == '<' || tmp->path[0] == '>' ||
        tmp->path[0] == '&' || tmp->path[0] == '|')
        && check_next(tmp)) {
            write(2, "Missing name for redirect.\n", 27);
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}

int multicommand(char *line, mysh_t *mysh)
{
    char **tab = NULL;
    list_t *list = NULL;

    if (check_separators(line) == 0)
        return 0;
    tab = exec_tab(line);
    list = create_list(tab);
    multi_exec(list, mysh);
    return 1;
}
