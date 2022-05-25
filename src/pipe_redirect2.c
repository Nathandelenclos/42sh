/*
** EPITECH PROJECT, 2022
** B-PSU-210-LIL-2-1-minishell2-david.plouvier
** File description:
** pipe_redirect2
*/

#include "mysh.h"

int nb_pipes(char **arg)
{
    int count = 0;

    for (int i = 0; arg[i + 1] != NULL; i++)
        if (compar_str(arg[i], "|") == 1 && compar_str(arg[i + 1], "|") != 1)
            count++;
    return (count);
}

void mid_pipe(char **arg, minishell_t *minishell)
{
    int pid;

    if (pipe(minishell->fd2) == -1)
        exit(84);
    pid = fork();
    if (pid == 0) {
        dup2(minishell->fd1[0], 0);
        dup2(minishell->fd2[1], 1);
        close_mid(minishell);
        execve_management(arg, minishell);
    } else {
        close(minishell->fd1[0]);
        close(minishell->fd1[1]);
        minishell->fd1[0] = minishell->fd2[0];
        minishell->fd1[1] = minishell->fd2[1];
    }
}

void last_pipe(char **arg, minishell_t *minishell)
{
    int pid;

    pid = fork();
    if (pid == 0) {
        dup2(minishell->fd1[0], STDIN_FILENO);
        close(minishell->fd1[0]);
        close(minishell->fd1[1]);
        execve_management(arg, minishell);
    } else {
        close(minishell->fd1[0]);
        close(minishell->fd1[1]);
        waitpid(pid, NULL, 0);
    }
}

void first_pipe(char **arg, minishell_t *minishell)
{
    int pid;

    if (pipe(minishell->fd1) == -1)
        exit(84);
    pid = fork();
    if (pid == 0) {
        dup2(minishell->fd1[1], STDOUT_FILENO);
        close(minishell->fd1[0]);
        close(minishell->fd1[1]);
        execve_management(arg, minishell);
    }
}

void fork_pipe_man(char **arg, minishell_t *minishell, int index, int nb_pipe)
{
    if (index == 0)
        first_pipe(arg, minishell);
    else if (index != nb_pipe - 1)
        mid_pipe(arg, minishell);
    else
        last_pipe(arg, minishell);
}
