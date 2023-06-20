/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** fonctions
*/

#include "../includes/my.h"

int my_strlen(char const *str)
{
    int i = 0;
    for (; str[i] != 0; i++);
    return i;
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (; s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'; i++);
    return s1[i] - s2[i];
}

char *my_strcat(char *dest, char const *src)
{
    int len = my_strlen(dest);
    int i = 0;
    char *temp = malloc(sizeof(char) * (len + my_strlen(src) + 1));

    for (int j = 0; j < len; j++)
        temp[j] = dest[j];
    for (; src[i] != 0; i++)
        temp[len + i] = src[i];
    temp[len + i] = 0;
    return temp;
}

int is_letter(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_')
        return 1;
    return 0;
}

int is_num(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}
