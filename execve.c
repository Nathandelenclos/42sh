/*
** EPITECH PROJECT, 2022
** B-PSU-101-LIL-1-1-minishell1-david.plouvier
** File description:
** execve.c
*/

#include "mysh.h"

int check_access(char **arg, minishell_t *minishell)
{
    char *command = concat_str("/", arg[0]);
    char **path = return_line(minishell, "PATH", "=:\0");

    if (path == NULL)
        return (1);
    for (int i = 1; path[i] != NULL; i++) {
        if (access(concat_str(path[i], command), X_OK) == 0) {
            return (do_execve_no_bin(arg, minishell,
            concat_str(path[i], command)));
        }
    }
    return (1);
}

int execve_management(char **arg, minishell_t *minishell)
{
    if (((arg[0][0] == '.' && arg[0][1] == '/') || absolut_path(arg)
== 0) && execve(bin_exe(arg), arg, minishell->cpyenv) == -1) {
        write(2, arg[0], my_strlen(arg[0]));
        write(2, ": Command not found.\n", 21);
        exit(1);
    }
    if (check_access(arg, minishell) == 1) {
        write(2, arg[0], my_strlen(arg[0]));
        write(2, ": Command not found.\n", 21);
        exit(1);
    }
    return (0);
}

int fork_management(char **arg, minishell_t *minishell)
{
    pid_t pid;
    int status = 0;

    if (if_builtin_in_pipe(arg, minishell, 3) == 0)
        return (0);
    pid = fork();
    if (pid == 0) {
        execve_management(arg, minishell);
        return (0);
    } else {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status))
            status = WEXITSTATUS(status);
        minishell->rtnval = status;
        return (0);
    }
}
