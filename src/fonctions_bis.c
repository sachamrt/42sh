/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** 42sh
*/

#include "../includes/my.h"

int is_alphanumeric(char *string)
{
    if (string == NULL)
        return 0;

    while (string[0]) {
        if (!((string[0] >= 'a' && string[0] <= 'z') ||
        (string[0] >= 'A' && string[0] <= 'Z') ||
        (string[0] >= '0' && string[0] <= '9')))
            return 0;
        string++;
    }
    return 1;
}
