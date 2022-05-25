/*
** EPITECH PROJECT, 2022
** B-PSU-101-LIL-1-1-minishell1-david.plouvier
** File description:
** main.c
*/

#include "mysh.h"
#include "my.h"

void clear_all(minishell_t *minishell)
{
    free_dbl_tab(minishell->cpyenv);
    free(minishell);
}

int choice_fonction(char **arg, minishell_t *minishell)
{
    char *name[6] = {"cd", "env", "setenv",
    "unsetenv", "exit", 0};

    int (*doit[6])(char **, minishell_t *) = {my_cd, my_printenv,
    my_setenv, my_unsetenv, my_exit, NULL};
    for (int j = 0; j < 5; j++) {
        if (compar_str(arg[0], name[j]) == 1) {
            minishell->rtnval = doit[j](arg, minishell);
            return (0);
        }
        if (j == 4) {
            return (execve_management(arg, minishell));
        }
    }
    return (0);
}

char **in_infin_loop(minishell_t *minishell, char **arg)
{
    char **pars_p = NULL;

    for (int i = 0; arg[i]; i++) {
        pars_p = str_to_word_array(arg[i], "|");
        choice_case_pipe(pars_p, minishell);
        free_dbl_tab(pars_p);
    }
    free_dbl_tab(arg);
    return (arg);
}

void infin_loop(minishell_t *minishell)
{
    char *inp = NULL;
    char **arg = NULL;
    size_t len = 0;

    while (1) {
        my_printf(1, "%s", isatty(0) ? "$> " : "");
        if (getline(&inp, &len, stdin) == -1) {
            my_printf(1, "%s", isatty(0) ? "exit\n" : "");
            exit(minishell->rtnval);
        }
        if (inp[0] == '\n')
            continue;
        arg = str_to_word_array(inp, ";\n");
        arg = in_infin_loop(minishell, arg);
    }
}

int main(int ac, char **av, char **env)
{
    minishell_t *minishell = malloc(sizeof(minishell_t));
    int rtn = 0;

    if (minishell == NULL)
        exit(84);
    minishell->cpyenv = copydbltab(0, env);
    minishell->rtnval = 0;
    infin_loop(minishell);
    rtn = minishell->rtnval;
    clear_all(minishell);
    return (rtn);
}
