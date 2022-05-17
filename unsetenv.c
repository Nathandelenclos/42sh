/*
** EPITECH PROJECT, 2022
** B-PSU-101-LIL-1-1-minishell1-david.plouvier
** File description:
** unsetenv.c
*/

#include "mysh.h"

void shift_lines(minishell_t *minishell, int i)
{
    int len = 0;

    for (i = i + 1; minishell->cpyenv[i] != NULL; i++) {
        len = my_strlen(minishell->cpyenv[i]);
        free(minishell->cpyenv[i - 1]);
        minishell->cpyenv[i - 1] = malloc(sizeof(char) * len + 1);
        minishell->cpyenv[i - 1][len] = '\0';
        for (int j = 0; j < len; j++) {
            minishell->cpyenv[i - 1][j] = minishell->cpyenv[i][j];
        }
    }
    free(minishell->cpyenv[i]);
}

int free_specific_line(minishell_t *minishell, char **arg, int narg)
{
    char **argenv = NULL;

    for (int i = 0; minishell->cpyenv[i] != NULL; i++) {
        argenv = str_to_word_array(minishell->cpyenv[i], "=\n");
        if (compar_str(argenv[0], arg[narg]) == 1) {
            free_dbl_tab(argenv);
            shift_lines(minishell, i);
            minishell->cpyenv = copydbltab(-1, minishell->cpyenv);
            return (0);
        }
        free_dbl_tab(argenv);
    }
    return (0);
}

int my_unsetenv(char **arg, minishell_t *minishell)
{
    if (arg[1] == NULL) {
        write(2, "unsetenv: Too few arguments.\n", 29);
        return (1);
    }
    for (int i = 1; arg[i] != NULL; i++)
        free_specific_line(minishell, arg, i);
    return (0);
}
