/*
** EPITECH PROJECT, 2024
** vector
** File description:
** test_init
*/

#include <criterion/assert.h>
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <stdio.h>
#include "vector.h"

Test(simple_push_back, vector)
{
    char *str = init_vector(sizeof(char));
    char c = 'a';
    char end = '\0';

    str = push_back_vector(str, &c);
    str = push_back_vector(str, &end);
    cr_assert_str_eq(str, "a");
    free_vector(str);
}

Test(simple_pop_back, vector)
{
    char *str = init_vector(sizeof(char));
    char *tmp = "abcdefgh";
    char end = '\0';

    for (int i = 0; tmp[i] != '\0'; i++)
        str = push_back_vector(str, &tmp[i]);
    popback_vector(str);
    str = push_back_vector(str, &end);
    cr_assert_str_eq(str, "abcdefg");
    free_vector(str);
}

Test(simple_size, vector)
{
    char *array = init_vector(sizeof(char));
    int added = 10;
    int removed = 4;

    for (int i = 0; i < added; i++)
        array = push_back_vector(array, &i);
    for (int i = 0; i < removed; i++) {
        popback_vector(array);
    }
    cr_assert_eq(vector_size(array), added - removed);
    free_vector(array);
}

Test(simple_push_front, vector)
{
    char *str = init_vector(sizeof(char));
    char *tmp = "abcdefgh";
    char end = '\0';

    for (int i = 0; tmp[i] != '\0'; i++)
        str = push_front_vector(str, &tmp[i]);
    str = push_back_vector(str, &end);
    cr_assert_str_eq(str, "hgfedcba");
    free_vector(str);
}

Test(simple_push_index, vector)
{
    char *str = init_vector(sizeof(char));
    char *tmp = "abcdefgh";
    char special = '@';
    char end = '\0';

    for (int i = 0; tmp[i] != '\0'; i++)
        str = push_front_vector(str, &tmp[i]);
    str = push_index_vector(str, 3, &special);
    str = push_back_vector(str, &end);
    cr_assert_str_eq(str, "hgf@edcba");
    free_vector(str);
}

Test(simple_push_index_bigger_index, vector)
{
    char *str = init_vector(sizeof(char));
    char *tmp = "abcdefgh";
    char *soluce = "abcdefgh____________@";
    char special = '@';

    for (int i = 0; tmp[i] != '\0'; i++)
        str = push_back_vector(str, &tmp[i]);
    str = push_index_vector(str, 20, &special);
    for (size_t i = 0; i < vector_size(str); i++) {
        if (soluce[i] == '_') {
            cr_assert_eq(str[i], '\0');
        } else {
            cr_assert_eq(str[i], soluce[i]);
        }
    }
    free_vector(str);
}

Test(pop_back_push_index_bigger_index, vector)
{
    char *str = init_vector(sizeof(char));
    char *tmp = "abcdefgh";
    char *soluce = "abcdefgh____________@";
    char special = '@';

    for (int i = 0; tmp[i] != '\0'; i++)
        str = push_back_vector(str, &tmp[i]);
    //popback_vector(str);
    str = push_index_vector(str, 20, &special);
    for (size_t i = 0; i < vector_size(str); i++) {
        if (soluce[i] == '_') {
            cr_assert_eq(str[i], '\0');
        } else {
            cr_assert_eq(str[i], soluce[i]);
        }
    }
    free_vector(str);
}

Test(simple_pop_front, vector)
{
    char *str = init_vector(sizeof(char));
    char *tmp = "abcdefgh";
    char end = '\0';

    for (int i = 0; tmp[i] != '\0'; i++)
        str = push_back_vector(str, &tmp[i]);
    popfront_vector(str);
    str = push_back_vector(str, &end);
    cr_assert_str_eq(str, "bcdefgh");
    free_vector(str);
}

Test(simple_pop_index, vector)
{
    char *str = init_vector(sizeof(char));
    char *tmp = "abcdefgh";
    char end = '\0';

    for (int i = 0; tmp[i] != '\0'; i++)
        str = push_back_vector(str, &tmp[i]);
    pop_index_vector(str, 3);
    str = push_back_vector(str, &end);
    cr_assert_str_eq(str, "abcefgh");
    free_vector(str);
}

Test(simple_concat, vector)
{
    char *first_vector = init_vector(sizeof(char));
    char *second_vector = init_vector(sizeof(char));
    char *final_vector = NULL;
    char *first = "abc";
    char *second = "def";
    char end = '\0';

    for (int i = 0; first[i] && second[i]; ++i) {
        push_back_vector(first_vector, &first[i]);
        push_back_vector(second_vector, &second[i]);
    }
    second_vector = push_back_vector(second_vector, &end);
    final_vector = concat_vector(2, first_vector, second_vector);
    cr_assert_str_eq(final_vector, "abcdef");
    free_vector(first_vector);
    free_vector(second_vector);
    free_vector(final_vector);
}

Test(multiple_concat, vector)
{
    char *first_vector = init_vector(sizeof(char));
    char *final_vector = NULL;
    char *first = "abc";
    char end = '\0';

    for (int i = 0; first[i]; ++i) {
        push_back_vector(first_vector, &first[i]);
    }
    final_vector = concat_vector(4, first_vector, first_vector, first_vector, first_vector);
    final_vector = push_back_vector(final_vector, &end);
    cr_assert_str_eq(final_vector, "abcabcabcabc");
    free_vector(first_vector);
    free_vector(final_vector);
}
<<<<<<< Updated upstream
=======

int sort(void *a, void *b)
{
    return *(char *)b - *(char *)a;
}

Test(simple_sort, vector)
{
    char *vector = init_vector(sizeof(char));
    char *to_fill = "azerty";
    char end = '\0';

    for (int i = 0; to_fill[i]; i++) {
        vector = push_back_vector(vector, &to_fill[i]);
    }
    quick_sort_vector(vector, sort);
    vector = push_back_vector(vector, &end);
    cr_assert_str_eq(vector, "aertyz");
    free_vector(vector);
}

Test(complex_sort, vector)
{
    char *vector = init_vector(sizeof(char));
    char *to_fill = "azertyuiopqsdfghjklmwxcvbn";
    char end = '\0';

    for (int i = 0; to_fill[i]; i++) {
        vector = push_back_vector(vector, &to_fill[i]);
    }
    quick_sort_vector(vector, sort);
    vector = push_back_vector(vector, &end);
    cr_assert_str_eq(vector, "abcdefghijklmnopqrstuvwxyz");
    free_vector(vector);
}

Test(index_of, vector)
{
    char *vector = init_vector(sizeof(char));
    char *to_fill = "azerty";
    char not_here = 'i';

    for (int i = 0; i < 6; i++) {
        push_back_vector(vector, &to_fill[i]);
    }
    cr_assert_eq(index_of_vector(vector, &vector[1]), 1);
    cr_assert_eq(index_of_vector(vector, &not_here), -1);
}
>>>>>>> Stashed changes
