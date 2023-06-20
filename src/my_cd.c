/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** cd
*/

#include "../includes/my.h"

char *get_user_path(void)
{
    char *path = malloc(sizeof(char) * 1000);
    char *result = getcwd(path, 1000);
    int count = 0;

    for (int i = 0; result[i] != 0; i++) {
        if (result[i] == '/')
            count++;
        if (count == 3) {
            result[i] = 0;
            break;
        }
    }
    return result;
}

int is_dir(char *path)
{
    DIR *dir = opendir(path);

    if (dir == NULL) {
        write(2, path, my_strlen(path));
        write(2, ": Not a directory.\n", 19);
        return -1;
    }
    return 0;
}

char *check_directory(char *path, char *prev_path)
{
    int check = 0;
    char *prev = malloc(sizeof(char) * 1000);

    if (is_dir(path) == -1)
        return prev_path;
    getcwd(prev, 1000);
    check = chdir(path);
    if (check == -1) {
        write(2, path, my_strlen(path));
        write(2, ": No such file or directory.\n", 29);
        return prev_path;
    }
    return prev;
}

char *get_prev_path(void)
{
    char *path = malloc(sizeof(char) * 1000);

    getcwd(path, 1000);
    return path;
}

int my_cd(char **tab, path_hist **prev_path)
{
    int check = 0;
    char *path = get_user_path();
    char *prev = get_prev_path();

    if (tab[1] == NULL || tab[1][0] == '~') {
        (*prev_path)->path = prev;
        chdir(path);
    } else if (tab[1][0] == '-') {
        chdir((*prev_path)->path);
        (*prev_path)->path = prev;
    } else
        (*prev_path)->path = check_directory(tab[1], (*prev_path)->path);
    return 0;
}
