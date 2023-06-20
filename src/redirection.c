/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** redirection
*/

#include "../includes/my.h"

int is_redirect(list_t *list)
{
    for (list_t *tmp = list; tmp; tmp = tmp->next) {
        if (tmp->path[0] == '>' || tmp->path[0] == '<')
            return 1;
    }
    return 0;
}

void input_redirect(char *cmd, mysh_t *mysh, char *file)
{
    int fd;

    if (access(file, F_OK) == -1) {
        write(2, file, my_strlen(file));
        write(2, ": No such file or directory.\n", 29);
        return;
    }
    fd = open(file, O_RDONLY);
    dup2(fd, STDIN_FILENO);
    line_checker(cmd, mysh);
    close(fd);
}

int check_word(char *word, char *line)
{
    char *tmp = strdup(line);

    if (strcmp(cut_line(tmp), word) == 0)
        return 1;
    return 0;
}

void double_input(char *cmd, mysh_t *mysh, char *word)
{
    char *line = NULL;
    size_t len = 0;
    int fd = open(".temp", O_CREAT | O_WRONLY | O_RDONLY | O_TRUNC, 0666);

    while (1) {
        write(1, "> ", 2);
        getline(&line, &len, stdin);
        if (check_word(word, line))
            break;
        else
            write(fd, line, strlen(line));
        line = NULL;
    }
    close(fd);
    fd = open(".temp", O_RDONLY);
    dup2(fd, STDIN_FILENO);
    line_checker(cmd, mysh);
}

list_t *redirection(int *in_fd, list_t *list, mysh_t *mysh)
{
    char **file = my_str_tok(list->next->next->path, " ");
    char *cmd = list->path;
    int i = 1;

    while (file[i] != NULL)
        cmd = my_strcat(cmd, file[i++]);
    if (my_strcmp(list->next->path, ">>") == 0)
        output_redirect(in_fd, cmd, mysh, file[0]);
    if (my_strcmp(list->next->path, ">") == 0)
        output_redirect(in_fd, cmd, mysh, file[0]);
    if (my_strcmp(list->next->path, "<") == 0)
        input_redirect(cmd, mysh, file[0]);
    if (my_strcmp(list->next->path, "<<") == 0)
        double_input(cmd, mysh, file[0]);
    return list->next->next;
}
