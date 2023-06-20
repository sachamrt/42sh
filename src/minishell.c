/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** minishell
*/

#include "../includes/my.h"

char *cut_line(char *line)
{
    int len = my_strlen(line);

    if (line[len - 1] == '\n')
        line[len - 1] = 0;
    return line;
}

int check_command(int i, char **tab, mysh_t *mysh)
{
    switch (i) {
        case 1:
            return my_cd(tab, &mysh->hist);
        case 2:
            exit(0);
        case 3:
            return my_env(mysh);
        case 4:
            return env_var(tab, mysh);
        case 6:
            return my_alias(tab, mysh);
        case 7:
            return my_unalias(tab, mysh);
        case 8:
            return my_history(tab, mysh);
        case 9:
            return local_variable(mysh, tab);
        default:
            return exec(tab, mysh);
    }
}

char **get_command(char *line, mysh_t *mysh)
{
    char **temp = my_str_tok(line, "\"");
    char **tab;

    if (temp == NULL)
        return NULL;
    tab = my_str_tok(temp[0], " \t");
    if (temp[1] != NULL)
        tab = tab_fusion(tab, temp);
    if (return_alias_node(tab[0], mysh->aliases) != NULL)
        tab = my_str_tok(strdup(return_alias_node(tab[0], mysh->aliases)->cmd),
        " \t");
    return tab;
}

int line_checker(char *line, mysh_t *mysh)
{
    char **t;
    int i = 0;

    if (my_strlen(line) < 2)
        t = my_str_to_word_array(line, ' ');
    else
        t = get_command(line, mysh);
    if (t == NULL)
        return 0;
    add_history(line, mysh->history, mysh);
    i = is_var_cmd(t, mysh);
    my_strcmp(t[0], "cd") == 0 ? i = 1 : 0;
    my_strcmp(t[0], "exit") == 0 ? i = 2 : 0;
    my_strcmp(t[0], "env") == 0 ? i = 3 : 0;
    strcmp(t[0], "setenv") == 0 | strcmp(t[0], "unsetenv") == 0 ? i = 4 : 0;
    my_strcmp(t[0], "alias") == 0 ? i = 6 : 0;
    my_strcmp(t[0], "unalias") == 0 ? i = 7 : 0;
    t[0][0] == '!' ? i = 8 : 0;
    return check_command(i, t, mysh);
}

void shell(char **env)
{
    mysh_t *mysh = malloc(sizeof(mysh_t));
    init_sh(mysh, env);
    char *line = NULL;
    char *temp = NULL;
    size_t size = 0;

    while (1) {
        if (isatty(0))
            display_prompt();
        if (getline(&line, &size, stdin) < 0)
            break;
        if (line[0] == '\n' || (my_strlen(line) == 2 && line[0] == ' '))
            continue;
        if (multicommand(cut_line(line), mysh) == 1)
            continue;
        temp = strdup(line);
        line_checker(cut_line(line), mysh);
    }
}
