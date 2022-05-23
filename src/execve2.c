/*
** EPITECH PROJECT, 2022
** B-PSU-101-LIL-1-1-minishell1-david.plouvier
** File description:
** execve2.c
*/

#include "mysh.h"

void close_mid(minishell_t *minishell)
{
    close(minishell->fd2[0]);
    close(minishell->fd2[1]);
    close(minishell->fd1[0]);
    close(minishell->fd1[1]);
}

void dup_for_builtin(minishell_t *minishell, int state)
{
    if (state == 0) {
        dup2(minishell->fd1[1], STDOUT_FILENO);
        close(minishell->fd1[1]);
    }
    if (state == 1) {
        dup2(minishell->fd1[0], 0);
        dup2(minishell->fd2[1], 1);
        close(minishell->fd2[1]);
        close(minishell->fd1[0]);
    }
    if (state == 2) {
        dup2(minishell->fd1[0], STDIN_FILENO);
        close(minishell->fd1[0]);
    }
}

int absolut_path(char **arg)
{
    for (int k = 0; k < my_strlen(arg[0]); k++)
        if (arg[0][k] == '/')
            return (0);
    return (1);
}

char *bin_exe(char **arg)
{
    int count = 0;
    char *bin = NULL;

    if (arg[0][0] == '.' && arg[0][1] == '/') {
        for (int i = 1; i < my_strlen(arg[0]); i++)
            count++;
        bin = malloc(sizeof(char) * count + 1);
        bin[count] = '\0';
        for (int i = 1; i < my_strlen(arg[0]); i++)
            bin[i - 1] = arg[0][i];
    } else if (absolut_path(arg) == 0 && arg[0][0] != '.') {
        bin = my_strdup(arg[0]);
        return (bin);
    }
    bin = concat_str(check_cd(), bin);
    return (bin);
}

int do_execve_no_bin(char **arg, minishell_t *minishell, char *path)
{
    if (execve(path, arg, minishell->cpyenv) == -1)
        return (1);
    return (0);
}
