/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** main
*/

#include "../includes/my.h"

int main(int ac, char **av, char **env)
{
    if (ac != 1)
        return 84;
    shell(env);
    return 0;
}
