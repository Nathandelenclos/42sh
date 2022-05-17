/*
** EPITECH PROJECT, 2022
** B-PSU-101-LIL-1-1-minishell1-david.plouvier
** File description:
** dbl_tab_fonctions.c
*/

#include "mysh.h"

char **str_to_word_array(char *str, char *sep)
{
    int line = my_strlen_str_split(str, sep);
    char **spl = malloc(sizeof(char *) * (line + 1));
    int j = 0;
    int k = 0;
    int c = 0;

    for (int i = 0; i < line; i++) {
        while (char_checker(str[j], sep) == 1)
            j++;
        for (; char_checker(str[j], sep) == 0 && str[j] != '\0'; j++)
            c++;
        spl[i] = malloc(sizeof(char) * (c + 1));
        for (; k < c; k++)
            spl[i][k] = str[j - c + k];
        spl[i][k] = '\0';
        c = 0;
        k = 0;
    }
    spl[line] = NULL;
    return (spl);
}

void print_dbl_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        write(1, tab[i], my_strlen(tab[i]));
        write(1, "\n", 1);
    }
}

void free_dbl_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}

char **copydbltab(int dif, char **env)
{
    char **cpy = malloc(sizeof(char *) * (nbr_lines(env) + 1 + dif));
    int i = 0;
    int len;

    for (; env[i] != NULL; i++) {
        len = my_strlen(env[i]);
        cpy[i] = malloc(sizeof(char) * (len + 1));
        cpy[i][len] = '\0';
        for (int j = 0; j < len; j++)
            cpy[i][j] = env[i][j];
    }
    cpy[i + dif] = NULL;
    return (cpy);
}

char **add_line_dbltab(int dif, char **src, char *str)
{
    int j = nbr_lines(src) + dif - 1;
    int len = my_strlen(str);
    char **tab = copydbltab(1, src);

    tab[j] = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i++)
        tab[j][i] = str[i];
    tab[j][len] = '\0';
    free_dbl_tab(src);
    return (tab);
}
