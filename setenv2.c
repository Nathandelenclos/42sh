/*
** EPITECH PROJECT, 2022
** B-PSU-101-LIL-1-1-minishell1-david.plouvier
** File description:
** setenv2.c
*/

#include "mysh.h"

int checkif_alphan1(char *str, minishell_t *minishell, char **arg)
{
    int len = my_strlen(str);

    if ((65 > str[0] || str[0] > 90) && (97 > str[0] || str[0] > 122)) {
        write (2, "setenv: Variable name must begin with a letter.\n", 48);
        return (1);
    }
    for (int i = 0; i < len; i++) {
        if ((48 > str[i] || str[i] > 57) && (65 > str[i] || str[i] > 90)
        && (97 > str[i] || str[i] > 122)) {
            write (2, "setenv: Variable name must contain \
alphanumeric characters.\n", 60);
            return (1);
        }
    }
    return (change_line_2arg(minishell, arg));
}

int cod_style(char *str1, int len1)
{
    for (int i = 0; i < len1; i++) {
        if ((48 > str1[i] || str1[i] > 57) && (65 > str1[i] || str1[i] > 90)
        && (97 > str1[i] || str1[i] > 122)) {
            write (2, "setenv: Variable name must contain \
alphanumeric characters.\n", 60);
            return (1);
        }
    }
    return (0);
}

int checkif_alphan2(char *str1, minishell_t *minishell, char **arg)
{
    int len1 = my_strlen(str1);
    int val = 0;

    if ((65 > str1[0] || str1[0] > 90) && (97 > str1[0] || str1[0] > 122)) {
        write (2, "setenv: Variable name must begin with a letter.\n", 48);
        return (1);
    }
    val = cod_style(str1, len1);
    if (val == 1)
        return (1);
    return (change_line_3arg(minishell, arg));
}

int cod_style_2arg(minishell_t *minishell, char **arg, char **argenv, int i)
{
    int len = my_strlen(arg[1]) + 2;
    int j = 0;

    free(minishell->cpyenv[i]);
    minishell->cpyenv[i] = malloc(sizeof(char) * len);
    minishell->cpyenv[i][len - 1] = '\0';
    for (; arg[1][j] != '\0'; j++)
        minishell->cpyenv[i][j] = arg[1][j];
    minishell->cpyenv[i][j++] = '=';
    free_dbl_tab(argenv);
    return (0);
}

int cod_style_3arg(minishell_t *minishell, char **arg, char **argenv, int i)
{
    int len = my_strlen(arg[1]) + my_strlen(arg[2]) + 2;
    int j = 0;

    free(minishell->cpyenv[i]);
    minishell->cpyenv[i] = malloc(sizeof(char) * len);
    minishell->cpyenv[i][len - 1] = '\0';
    for (; arg[1][j] != '\0'; j++)
        minishell->cpyenv[i][j] = arg[1][j];
    minishell->cpyenv[i][j++] = '=';
    for (int jj = j; arg[2][j - jj] != '\0'; j++)
        minishell->cpyenv[i][j] = arg[2][j - jj];
    free_dbl_tab(argenv);
    return (0);
}
