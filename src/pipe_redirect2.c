/*
** EPITECH PROJECT, 2022
** B-PSU-210-LIL-2-1-minishell2-david.plouvier
** File description:
** pipe_redirect2
*/

#include "mysh.h"

int mid_pipe(char **arg, minishell_t *minishell, int index)
{
    int pid2;

    if (pipe(minishell->fd2) == -1)
        exit(84);
    if (if_builtin_in_pipe(reset_tab(arg, index + 1, "|"), minishell, 1) == 0)
        return (0);
    pid2 = fork();
    if (pid2 == 0) {
        dup2(minishell->fd1[0], 0);
        dup2(minishell->fd2[1], 1);
        close_mid(minishell);
        execve_management(reset_tab(arg, index + 1, "|"), minishell);
    } else {
        close(minishell->fd1[0]);
        close(minishell->fd1[1]);
        minishell->fd1[0] = minishell->fd2[0];
        minishell->fd1[1] = minishell->fd2[1];
    }
    return (0);
}

int nb_pipes(char **arg)
{
    int count = 0;

    for (int i = 0; arg[i + 1] != NULL; i++)
        if (compar_str(arg[i], "|") == 1 && compar_str(arg[i + 1], "|") != 1)
            count++;
    return (count);
}

int fork_mid_pipe_man(char **arg, minishell_t *minishell, int index)
{
    if (nb_pipes(arg) == 1)
        return (0);
    for (int i = 0; i < index; i++)
        if (compar_str(arg[i], "|") == 1 && compar_str(arg[i + 1], "|") != 1)
            mid_pipe(arg, minishell, i);
    return (0);
}

int fork_last_pipe_man(char **arg, minishell_t *minishell, int index)
{
    int pid2;

    if (if_builtin_in_pipe(reset_tab(arg, index + 1, "|"), minishell, 2) == 0)
        return (0);
    pid2 = fork();
    if (pid2 == 0) {
        dup2(minishell->fd1[0], STDIN_FILENO);
        close(minishell->fd1[0]);
        close(minishell->fd1[1]);
        execve_management(reset_tab(arg, index + 1, "|"), minishell);
    } else {
        close(minishell->fd1[0]);
        close(minishell->fd1[1]);
        waitpid(pid2, NULL, 0);
    }
    return (0);
}

int fork_pipe_man(char **arg, minishell_t *minishell, int index)
{
    int pid;

    if (pipe(minishell->fd1) == -1)
        exit(84);
    if (if_builtin_in_pipe(reset_tab(arg, 0, "|"), minishell, 0) == 0) {
        fork_mid_pipe_man(arg, minishell, index);
        fork_last_pipe_man(arg, minishell, index);
        return (0);
    }
    pid = fork();
    if (pid == 0) {
        dup2(minishell->fd1[1], STDOUT_FILENO);
        close(minishell->fd1[0]);
        close(minishell->fd1[1]);
        execve_management(reset_tab(arg, 0, "|"), minishell);
    } else {
        fork_mid_pipe_man(arg, minishell, index);
        fork_last_pipe_man(arg, minishell, index);
    }
    return (0);
}
