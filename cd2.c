/*
** EPITECH PROJECT, 2022
** B-PSU-101-LIL-1-1-minishell1-david.plouvier
** File description:
** cd2.c
*/

#include "mysh.h"

char **get_oldpwd(char **oldpwd, char *buf)
{
    oldpwd = malloc(sizeof(char *) * 4);
    oldpwd[0] = my_strdup("setenv");
    oldpwd[1] = my_strdup("OLDPWD");
    oldpwd[3] = NULL;
    oldpwd[2] = my_strdup(buf);
    free(buf);
    return (oldpwd);
}

char **get_pwd(char **pwd, char *buf)
{
    pwd = malloc(sizeof(char *) * 4);
    pwd[0] = my_strdup("setenv");
    pwd[1] = my_strdup("PWD");
    pwd[3] = NULL;
    pwd[2] = my_strdup(buf);
    free(buf);
    return (pwd);
}

char **return_line(minishell_t *minishell, char *str, char *sep)
{
    char **argenv = NULL;

    for (int i = 0; minishell->cpyenv[i] != NULL; i++) {
        argenv = str_to_word_array(minishell->cpyenv[i], sep);
        if (compar_str(argenv[0], str) == 1) {
            return (argenv);
        }
        free_dbl_tab(argenv);
    }
    argenv = NULL;
    return (argenv);
}

char *concat_str(char *str1, char *str2)
{
    int len = my_strlen(str1) + my_strlen(str2);
    char *str = malloc(sizeof(char) * len + 1);
    int i = 0;

    str[len] = '\0';
    for (; i < my_strlen(str1); i++) {
        str[i] = str1[i];
    }
    for (int j = 0; j < my_strlen(str2); j++) {
        str[i] = str2[j];
        i++;
    }
    return (str);
}

int wrong_chdir(char **arg)
{
    int fd = open(arg[1], O_RDONLY);

    if (fd != -1) {
        close(fd);
        write (2, arg[1], my_strlen(arg[1]));
        write (2, ": Not a directory.\n", 19);
        return (1);
    }
    write (2, arg[1], my_strlen(arg[1]));
    write (2, ": No such file or directory.\n", 29);
    return (1);
}
