/*
** EPITECH PROJECT, 2023
** redirect
** File description:
** redirects the output for tests purposes
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "header.h"

static size_t my_arraylen(char const *const *const array)
{
    int i;

    for (i = 0; array[i] != NULL; i++);
    return i;
}

void redirect_all_stdout(void)
{
        cr_redirect_stdout();
        cr_redirect_stderr();
}

// THIS REQUIRES A NULL AT THE END
void assert_char_arrays(char **actual, char **expected)
{
    cr_assert(my_arraylen(CONST_A(actual)) == my_arraylen(CONST_A(actual)));
    for (int i = 0; actual[i] != NULL; i++) {
        cr_assert_strings_eq(actual[i], expected[i]);
    }
}

/*
** TEMPLATES:

Test(TEST_NAME, TEST_SECTION)
{
    cr_assert_eq(1, 1);
}

Test(TEST_NAME, TEST_SECTION, .init = redirect_all_std)
{
    //your prints
    cr_assert_stdout_eq_str("WHATEVER");
*/