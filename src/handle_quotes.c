/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** handle quote
*/

#include "../includes/my.h"

char **tab_fusion(char **tab, char **temp)
{
    char **result = malloc(sizeof(char *) * (len_tab(tab) + len_tab(temp) + 1));
    int i = 0;

    for (; tab[i] != NULL; i++)
        result[i] = tab[i];
    for (int j = 1; temp[j] != NULL; i++, j++)
        result[i] = temp[j];
    result[i] = NULL;
    return result;
}
