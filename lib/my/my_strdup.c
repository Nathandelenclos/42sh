/*
** EPITECH PROJECT, 2021
** strdup
** File description:
** my strdup
*/

#include <stdlib.h>
#include "my.h"
#include "../linked_list/list.h"

char *my_strdup(char *string)
{
    if (string == NULL)
        return NULL;
    int len = my_strlen(string);
    char *final = MALLOC(sizeof(char ) * len + 1);
    for (int i = 0; i < len; ++i)
        final[i] = string[i];
    final[len] = '\0';
    return final;
}
