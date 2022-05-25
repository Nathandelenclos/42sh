/*
** EPITECH PROJECT, 2021
** 42sh - tests
** File description:
** tests for str_functions
*/

#include "../include/mysh.h"
#include <string.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(my_strlen, count_char_in_string)
{
    cr_assert(my_strlen("12345678\n") == 9);
}

Test(my_strdup, dup_string)
{
    char *base = "test";
    cr_assert(!strcmp(base, my_strdup(base)));
}

Test(compar_str, compar_str_base_with_strcmp)
{
    char *base = "test";
    cr_assert((!compar_str(base, base)) == strcmp(base, base));
}

Test(my_strlen_str_split, my_strlen_str_split_string)
{
    char *base = "test test";
    cr_assert(my_strlen_str_split(base, " ") == 2);
}
