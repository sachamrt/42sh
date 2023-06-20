/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** path
*/

#include "../includes/my.h"

char *copy_path(char *path, char *cmd)
{
    int size = my_strlen(path) + my_strlen(cmd) + 1;
    char *temp = malloc(sizeof(char) * size);

    temp = my_strcpy(temp, path);
    temp = my_strcat(temp, "/");
    temp = my_strcat(temp, cmd);
    return temp;
}

char *check_exec_path(char **tab, char *value)
{
    char *temp;
    char **path = my_str_to_word_array(value, ':');

    if (tab[0][0] == '.')
        return NULL;
    if (path == NULL)
        return NULL;
    for (int i = 0; path[i] != NULL; i++) {
        temp = copy_path(path[i], tab[0]);
        if (access(temp, F_OK) == 0)
            return temp;
        free(temp);
    }
    return NULL;
}

char *get_path_exec(char **tab, list_env_t *list)
{
    list_env_t *tmp = list;
    int ret = 0;

    while (tmp != NULL) {
        if (my_strcmp(tmp->name, "PATH") == 0) {
            ret = 1;
            break;
        }
        tmp = tmp->next;
    }
    if (ret == 0)
        return NULL;
    return check_exec_path(tab, tmp->value);
}
