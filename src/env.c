/*
** EPITECH PROJECT, 2022
** B-PSU-101-LIL-1-1-minishell1-david.plouvier
** File description:
** builtins.c
*/

#include "mysh.h"

int my_printenv(char **arg, minishell_t *minishell)
{
    if (arg[1] == NULL) {
        print_dbl_tab(minishell->cpyenv);
        return (0);
    } else {
        write (2, "env: '", 7);
        write (2, arg[1], my_strlen(arg[1]));
        write (2, "': No such file or directory\n", 29);
        return (127);
    }
}
