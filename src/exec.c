/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** exec
*/

#include "../includes/my.h"

char *is_exec(char **tab, mysh_t *mysh)
{
    char *path = get_path_exec(tab, mysh->list);
    struct stat st;

    if (path != NULL)
        return path;
    if (access(tab[0], F_OK) == 0) {
        stat(tab[0], &st);
        if (access(tab[0], X_OK) == 0 && !(S_ISDIR(st.st_mode)))
            return tab[0];
        else {
            write(2, tab[0], my_strlen(tab[0]));
            write(2, ": Permission denied.\n", 21);
            return NULL;
        }
    } else {
        write(2, tab[0], my_strlen(tab[0]));
        write(2, ": Command not found.\n", 21);
        return NULL;
    }
}

void error_handle(int status)
{
    if (WIFSIGNALED(status) && WTERMSIG(status) == SIGSEGV) {
        write(1, "Segmentation fault", 18);
        if (WCOREDUMP(status))
            write(1, " (core dumped)\n", 16);
        else
            write(1, "\n", 1);
    }
    if (WIFSIGNALED(status) && WTERMSIG(status) == SIGFPE) {
        write(1, "Floating exception", 18);
        if (WCOREDUMP(status))
            write(1, " (core dumped)\n", 16);
        else
            write(1, "\n", 1);
    }
}

void error_exec(char *cmd)
{
    if (errno == ENOEXEC) {
        write(2, cmd, my_strlen(cmd));
        write(2, ": Exec format error. Wrong Architecture.\n", 41);
    }
}

int exec(char **tab, mysh_t *mysh)
{
    char *path = is_exec(tab, mysh);
    pid_t pid;
    pid = fork();
    int status = 0;

    if (pid == -1)
        exit(0);
    if (pid == 0) {
        if (path == NULL)
            exit(84);
        if (execve(path, tab, NULL) == -1) {
            error_exec(tab[0]);
            exit(84);
        }
        exit(0);
    } else {
        wait(&status);
        error_handle(status);
    }
    return status;
}
