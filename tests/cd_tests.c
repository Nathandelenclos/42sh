/*
** EPITECH PROJECT, 2021
** 42sh - Tests
** File description:
** tests function cd
*/

#include "../include/mysh.h"
#include <string.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(check_cd, check_cd_function_true)
{
    cr_assert(!strcmp(getcwd(NULL, 0), check_cd()));
}

Test(absolut_path, check_is_absolut_path)
{
    char *arg[] = {"test"};
    cr_assert(absolut_path(arg));
}