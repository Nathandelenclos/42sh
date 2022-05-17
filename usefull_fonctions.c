/*
** EPITECH PROJECT, 2022
** B-PSU-101-LIL-1-1-minishell1-david.plouvier
** File description:
** usefull_fonctions.c
*/

#include "mysh.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int char_checker(char c, char *str)
{
    int lensep = my_strlen(str);

    for (int i = 0; i < lensep; i++) {
        if (str[i] == c) {
            return (1);
        }
    }
    return (0);
}

int nbr_lines(char **tab)
{
    int count = 0;

    for (int i = 0; tab[i] != NULL; i++)
        count++;
    return (count);
}

int sign(char const *str)
{
    int count = 0;
    int sign = 0;
    int j = 0;

    while (str[j] < '0' || str[j] > '9') {
        if (str[j] == '-') {
            count++;
        }
        j++;
    }
    if (count % 2 == 0)
        sign = 1;
    else
        sign = -1;
    return (sign);
}

int my_getnbr(char const *str)
{
    int lenstr = my_strlen(str);
    int strtoint = 0;
    int sign_t = sign(str);

    for (int i = 0; i < lenstr; i++) {
        if (str[i] >= '0' || '9' <= str[i]) {
            strtoint = 10 * strtoint;
            strtoint = strtoint + str[i] - 48;
        }
    }
    strtoint *= sign_t;
    return (strtoint);
}
