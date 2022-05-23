/*
** EPITECH PROJECT, 2022
** B-PSU-101-LIL-1-1-minishell1-david.plouvier
** File description:
** cd.c
*/

#include "mysh.h"

char *check_cd(void)
{
    size_t size = 1000;
    char *buf = malloc(sizeof(char) * size);

    buf[size - 1] = '\0';
    getcwd(buf, size);
    return (buf);
}

int cd_and_cd_wave(minishell_t *minishell)
{
    char **oldpwd = NULL;
    char **pwd = NULL;
    char **user = NULL;
    char *path = NULL;

    user = return_line(minishell, "USER", "=\0");
    path = concat_str("/home/", user[1]);
    oldpwd = get_oldpwd(oldpwd, check_cd());
    chdir(path);
    pwd = get_pwd(pwd, check_cd());
    my_setenv(oldpwd, minishell);
    my_setenv(pwd, minishell);
    free(path);
    free_dbl_tab(user);
    free_dbl_tab(pwd);
    free_dbl_tab(oldpwd);
    return (0);
}

int cd_minus(minishell_t *minishell)
{
    char **oldpwd = NULL;
    char **pwd = NULL;
    char **user = NULL;
    char *path = NULL;

    if ((user = return_line(minishell, "OLDPWD", "=\0")) == NULL) {
        write (2, ": No such file or directory.\n", 29);
        return (1);
    }
    path = my_strdup(user[1]);
    oldpwd = get_oldpwd(oldpwd, check_cd());
    chdir(path);
    pwd = get_pwd(pwd, check_cd());
    my_setenv(oldpwd, minishell);
    my_setenv(pwd, minishell);
    free(path);
    free_dbl_tab(user);
    free_dbl_tab(pwd);
    free_dbl_tab(oldpwd);
    return (0);
}

int cd_something(char **arg, minishell_t *minishell)
{
    char **oldpwd = NULL;
    char **pwd = NULL;
    char *buf = 0;

    buf = check_cd();
    if (chdir(arg[1]) == -1 && compar_str(arg[1], "home") != 1) {
        return (wrong_chdir(arg));
    } else if (compar_str(arg[1], "home") == 1) {
        write(1, "~\n", 2);
        chdir("/home");
    }
    oldpwd = get_oldpwd(oldpwd, buf);
    pwd = get_pwd(pwd, check_cd());
    my_setenv(oldpwd, minishell);
    my_setenv(pwd, minishell);
    free_dbl_tab(pwd);
    free_dbl_tab(oldpwd);
    return (0);
}

int my_cd(char **arg, minishell_t *minishell)
{
    if (arg[1] == NULL || (compar_str(arg[1], "~") == 1 && arg[2] == NULL)) {
        return (cd_and_cd_wave(minishell));
    }
    if (arg[2] == NULL && (compar_str(arg[1], "-") == 1 && arg[2] == NULL)) {
        return (cd_minus(minishell));
    }
    if (arg[2] == NULL) {
        return (cd_something(arg, minishell));
    } else {
        write (2, "cd: Too many arguments.\n", 25);
        return (1);
    }
    return (0);
}
