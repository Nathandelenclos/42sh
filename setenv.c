/*
** EPITECH PROJECT, 2022
** B-PSU-101-LIL-1-1-minishell1-david.plouvier
** File description:
** setenv.c
*/

#include "mysh.h"

int add_line_2arg(minishell_t *minishell, char **arg)
{
    int len = my_strlen(arg[1]) + 2;
    int j = 0;
    char *str = NULL;

    str = malloc(sizeof(char) * len);
    str[len - 1] = '\0';
    for (; arg[1][j] != '\0'; j++)
        str[j] = arg[1][j];
    str[j++] = '=';
    minishell->cpyenv = add_line_dbltab(1, minishell->cpyenv, str);
    return (0);
}

int change_line_2arg(minishell_t *minishell, char **arg)
{
    char **argenv = NULL;

    for (int i = 0; minishell->cpyenv[i] != NULL; i++) {
        argenv = str_to_word_array(minishell->cpyenv[i], "=\n");
        if (compar_str(argenv[0], arg[1]) == 1) {
            return (cod_style_2arg(minishell, arg, argenv, i));
        }
        free_dbl_tab(argenv);
    }
    return (add_line_2arg(minishell, arg));
}

int add_line_3arg(minishell_t *minishell, char **arg)
{
    int len = my_strlen(arg[1]) + my_strlen(arg[2]) + 2;
    int j = 0;
    char *str = NULL;

    str = malloc(sizeof(char) * len);
    str[len - 1] = '\0';
    for (; arg[1][j] != '\0'; j++)
        str[j] = arg[1][j];
    str[j++] = '=';
    for (int jj = j; arg[2][j - jj] != '\0'; j++)
        str[j] = arg[2][j - jj];
    minishell->cpyenv = add_line_dbltab(1, minishell->cpyenv, str);
    return (0);
}

int change_line_3arg(minishell_t *minishell, char **arg)
{
    char **argenv = NULL;

    for (int i = 0; minishell->cpyenv[i] != NULL; i++) {
        argenv = str_to_word_array(minishell->cpyenv[i], "=\n");
        if (compar_str(argenv[0], arg[1]) == 1) {
            return (cod_style_3arg(minishell, arg, argenv, i));
        }
        free_dbl_tab(argenv);
    }
    return (add_line_3arg(minishell, arg));
}

int my_setenv(char **arg, minishell_t *minishell)
{
    if (arg[1] == NULL) {
        print_dbl_tab(minishell->cpyenv);
        return (0);
    }
    if (arg[2] == NULL)
        return (checkif_alphan1(arg[1], minishell, arg));
    if (arg[3] == NULL)
        return (checkif_alphan2(arg[1], minishell, arg));
    else {
        write (2, "setenv: Too many arguments.\n", 28);
        return (1);
    }
    return (0);
}
