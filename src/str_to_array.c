/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** str to array
*/

#include "../includes/my.h"

char **malloc_tab(int len)
{
    char **tab = malloc(sizeof(char *) * len + 10);

    for (int i = 0; i < len; i++)
        tab[i] = malloc(sizeof(char) * len + 10);
    return tab;
}

char **malloc_tab_bis(int len_tab, int size)
{
    char **tab = malloc(sizeof(char *) * (len_tab + 1));

    for (int i = 0; i < len_tab; i++)
        tab[i] = malloc(sizeof(char) * (size + 1));
    return tab;
}

int count_words(char const *str, char delim)
{
    int nb_word = 0;

    while (*str) {
        while (*str && *str == delim)
            str++;
        while (*str && *str != delim)
            str++;
        if (*(str - 1) != delim)
            nb_word++;
    }
    return nb_word;
}

char **my_str_to_word_array(char *str, char delim)
{
    int j = 0;
    int k = 0;
    char **tab;
    int nb = 0;

    if (str == NULL || count_words(str, delim) <= 0)
        return NULL;
    nb = count_words(str, delim);
    tab = malloc_tab_bis(nb, my_strlen(str));
    while (*str) {
        for (; *str != 0 && *str == delim; str++);
        while (*str != 0 && *str != delim)
            tab[j][k++] = *str++;
        tab[j][k] = 0;
        if (*(str - 1) != delim)
            j++;
        k = 0;
    }
    tab[nb] = NULL;
    return tab;
}

char **my_str_tok(char *str, char *delim)
{
    char **tab = malloc(sizeof(char *) * my_strlen(str));
    int i = 0;
    int check = 0;

    for (int j = 0; str[j] != '\0'; j++) {
        check = 0;
        for (int k = 0; delim[k] != '\0'; k++)
            str[j] == delim[k] ? check = 1 : 0;
        if (check == 0)
            break;
    }
    if (check == 1)
        return NULL;
    tab[i] = strtok(str, delim);
    while (tab[i] != NULL) {
        i++;
        tab[i] = strtok(NULL, delim);
    }
    return tab;
}
