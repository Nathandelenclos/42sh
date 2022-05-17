/*
** EPITECH PROJECT, 2022
** B-PSU-210-LIL-2-1-minishell2-david.plouvier
** File description:
** pipe_redirect
*/

#include "mysh.h"

int index_last_pipe(char **arg)
{
    int index = 0;

    for (int i = 0; arg[i + 1] != NULL; i++) {
        if (compar_str(arg[i], "|") == 1 && compar_str(arg[i + 1], "|") != 1)
            index = i;
    }
    return (index);
}

int choice_case_pipe(char **arg, minishell_t *minishell)
{
    for (int i = 0; arg[i + 1] != NULL; i++)
        if (compar_str(arg[i], "|") == 1 && compar_str(arg[i + 1], "|") != 1)
            return (fork_pipe_man(arg, minishell, index_last_pipe(arg)));
    return (fork_management(arg, minishell));
}

char **reset_tab(char **tab, int i, char *c)
{
    char **newtab = NULL;
    int count = 0;

    for (int j = i; tab[j] != NULL; j++, count++)
        if (compar_str(tab[j], c) == 1)
            break;
    newtab = malloc(sizeof(char *) * (count + 1));
    if (newtab == NULL)
        exit(84);
    newtab[count] = NULL;
    for (int j = 0; j < count; j++, i++) {
        newtab[j] = malloc(sizeof(char) * my_strlen(tab[i] + 1));
        if (newtab[j] == NULL)
            exit(84);
        newtab[j] = tab[i];
        newtab[j][my_strlen(tab[i])] = '\0';
    }
    return (newtab);
}

void builtin_midpipe(minishell_t *minishell, int state)
{
    if (state == 1) {
        minishell->fd1[0] = minishell->fd2[0];
        minishell->fd1[1] = minishell->fd2[1];
    }
}

int if_builtin_in_pipe(char **arg, minishell_t *minishell, int state)
{
    char *name[6] = {"cd", "env", "setenv",
    "unsetenv", "exit", 0};
    int (*doit[6])(char **, minishell_t *) = {my_cd, my_printenv,
    my_setenv, my_unsetenv, my_exit, NULL};
    int save_input;
    int save_output;

    for (int j = 0; j <= 4; j++) {
        if (compar_str(arg[0], name[j]) == 1) {
            save_input = dup(0);
            save_output = dup(1);
            dup_for_builtin(minishell, state);
            minishell->rtnval = doit[j](arg, minishell);
            builtin_midpipe(minishell, state);
            dup2(save_input, 0);
            dup2(save_output, 1);
            return (0);
        }
    }
    return (1);
}
