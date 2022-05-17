/*
** EPITECH PROJECT, 2022
** B-PSU-101-LIL-1-1-minishell1-david.plouvier
** File description:
** str_fonctions.c
*/

#include "mysh.h"

int my_strlen(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

char *my_strdup(char *str)
{
    int len = my_strlen(str);
    char *res = malloc(sizeof(char) * (len + 1));

    for (int i = 0; i < len; i++)
        res[i] = str[i];
    res[len] = '\0';
    return (res);
}

int compar_str(char *str1, char *str2)
{
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);

    if (len1 != len2)
        return (0);
    for (int i = 0; i < len1; i++)
        if (str1[i] != str2[i])
            return (0);
    return (1);
}

int my_strlen_str_split(char const *str, char *sep)
{
    int i = 0;
    int line = -1;

    while (i < my_strlen(str)) {
        while (char_checker(str[i], sep) == 1)
            i++;
        line++;
        for (; char_checker(str[i], sep) == 0 && str[i] != '\0'; i++);
    }
    if (char_checker(str[my_strlen(str) - 1], sep) != 1)
        line++;
    return (line);
}
