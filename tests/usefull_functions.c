/*
** EPITECH PROJECT, 2021
** 42sh - tests
** File description:
** tests for function in usefull_functions
*/

#include "../include/mysh.h"
#include <string.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/redirect.h>

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_putchar, put_c_in_stdout, .init=redirect_all_stdout)
{
    my_putchar('c');
    cr_assert_stdout_eq_str("c");
}

Test(char_checker, check_c_in_char)
{
    cr_assert(char_checker('c', "char"));
}

Test(nbr_lines, count_nbr_line_of_tab_with_5line)
{
    char *tab[] = {"line", "line", "line", "line", "line"};
    cr_assert(nbr_lines(tab) == 5);
}

Test(my_getnbr, my_getnbr_of_42)
{
    cr_assert(my_getnbr("42") == 42);
}
