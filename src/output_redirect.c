/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** output redrect
*/

#include "../includes/my.h"

void output_redirect(int *in_fd, char *cmd, mysh_t *mysh, char *file)
{
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
    int fd = open(file, O_RDONLY | O_WRONLY | O_CREAT | O_TRUNC, mode);
    dup2(*in_fd, STDIN_FILENO);
    dup2(fd, STDOUT_FILENO);
    line_checker(cmd, mysh);
    close(*in_fd);
    close(fd);
}

void dbl_output_redirect(int *in_fd, char *cmd, mysh_t *mysh, char *file)
{
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
    int fd = open(file, O_RDONLY | O_WRONLY | O_APPEND, mode);

    dup2(fd, STDOUT_FILENO);
    line_checker(cmd, mysh);
    close(*in_fd);
    close(fd);
}
