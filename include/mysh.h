/*
** EPITECH PROJECT, 2022
** B-PSU-101-LIL-1-1-minishell1-david.plouvier
** File description:
** mysh.h
*/

#ifndef MYSH_H
    #define MYSH_H

    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <signal.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <sys/stat.h>
    #include <fcntl.h>


typedef struct minishell {
    char **cpyenv;
    int rtnval;
    int fd1[2];
    int fd2[2];
} minishell_t;

void my_putchar(char c);

int char_checker(char c, char *str);

int nbr_lines(char **tab);

int my_getnbr(char const *str);

int my_strlen(char const *str);

char *my_strdup(char *str);

int compar_str(char *str1, char *str2);

int my_strlen_str_split(char const *str, char *sep);

char **str_to_word_array(char *str, char *sep);

void print_dbl_tab(char **tab);

void free_dbl_tab(char **tab);

char **copydbltab(int dif, char **env);

char **add_line_dbltab(int dif, char **src, char *str);

int my_cd(char **arg, minishell_t *minishell);

int my_printenv(char **arg, minishell_t *minishell);

int my_setenv(char **arg, minishell_t *minishell);

int my_unsetenv(char **arg, minishell_t *minishell);

int my_exit(char **arg, minishell_t *minishell);

int checkif_alphan2(char *str1, minishell_t *minishell, char **arg);

int checkif_alphan1(char *str, minishell_t *minishell, char **arg);

int change_line_3arg(minishell_t *minishell, char **arg);

int change_line_2arg(minishell_t *minishell, char **arg);

char *check_cd(void);

char **get_oldpwd(char **oldpwd, char *buf);

char **get_pwd(char **pwd, char *buf);

char **return_line(minishell_t *minishell, char *str, char *sep);

char *concat_str(char *str1, char *str2);

int cod_style_2arg(minishell_t *minishell, char **arg, char **argenv, int i);

int cod_style_3arg(minishell_t *minishell, char **arg, char **argenv, int i);

int fork_management(char **arg, minishell_t *minishell);

int wrong_chdir(char **arg);

int absolut_path(char **arg);

char *bin_exe(char **arg);

int do_execve_no_bin(char **arg, minishell_t *minishell, char *path);

int choice_case_pipe(char **arg, minishell_t *minishell);

int execve_management(char **arg, minishell_t *minishell);

int fork_pipe_man(char **arg, minishell_t *minishell, int index);

int nb_pipes(char **arg);

char **reset_tab(char **tab, int i, char *c);

int choice_fonction(char **arg, minishell_t *minishell);

int if_builtin_in_pipe(char **arg, minishell_t *minishell, int state);

void dup_for_builtin(minishell_t *minishell, int state);

void close_mid(minishell_t *minishell);

#endif
