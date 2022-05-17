/*
** EPITECH PROJECT, 2022
** B-PSU-101-LIL-1-1-minishell1-david.plouvier
** File description:
** exit.c
*/

#include "mysh.h"

void process_exit(char **arg, minishell_t *minishell, int rtnval)
{
    write(1, "exit\n", 5);
    free_dbl_tab(arg);
    free_dbl_tab(minishell->cpyenv);
    free(minishell);
    exit(rtnval);
}

int error_exit(char **arg)
{
    int sign = 0;

    if (arg[1][0] == '-')
        sign = 1;
    for (int i = sign; arg[1][i] != '\0'; i++) {
        if (arg[1][i] < '0' || '9' < arg[1][i]) {
            write(2, "exit: Expression Syntax.\n", 25);
            return (1);
        }
    }
    return (0);
}

int my_exit(char **arg, minishell_t *minishell)
{
    if (arg[1] == NULL)
        process_exit(arg, minishell, 0);
    if (error_exit(arg) == 1)
        return (1);
    if (arg[2] == NULL)
        process_exit(arg, minishell, my_getnbr(arg[1]));
    write (2, "exit: Expression Syntax.\n", 25);
    return (1);
}
