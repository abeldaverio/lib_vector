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
#include "../include/vector.h"

static bool int_vector_equal(void *vector, int *comparaison)
{
    vector_t *vect = _get_vector_struct(vector);
    int *int_vector = (int *)vector;

    for (size_t i = 0; i < vect->stored; i++) {
        if (int_vector[i] != comparaison[i])
            return false;
    }
    return true;
}

Test(simple_push_back, int_vector)
{
    int *array = init_vector(sizeof(int));
    int i = 2;
    int soluce[] = {2};

    array = push_back_vector(array, &i);
    cr_assert(int_vector_equal(array, soluce));
    free_vector(array);
}

Test(simple_pop_back, int_vector)
{
    int *array = init_vector(sizeof(int));
    int tmp[] = {1, 2, 3, 4, 5, 6, 0};
    int soluce[] = {1, 2, 3, 4, 5};

    for (int i = 0; tmp[i] != 0; i++)
        array = push_back_vector(array, &tmp[i]);
    popback_vector(array);
    int_vector_equal(array, soluce);
    free_vector(array);
}

Test(simple_size, int_vector)
{
    int *array = init_vector(sizeof(int));
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

Test(simple_push_front, int_vector)
{
    int *array = init_vector(sizeof(int));
    int tmp[] = {1, 2, 3, 4, 5, 6, 0};
    int soluce[] = {6, 5, 4, 3, 2, 1};

    for (int i = 0; tmp[i] != 0; i++)
        array = push_front_vector(array, &tmp[i]);
    int_vector_equal(array, soluce);
    free_vector(array);
}

Test(simple_push_index, int_vector)
{
    int *array = init_vector(sizeof(int));
    int tmp[] = {1, 2, 3, 4, 5};
    int special = 10;
    int reference[] = {5, 4, 3, 10, 2, 1};

    for (int i = 0; i < 3; i++)
        array = push_front_vector(array, &tmp[i]);
    array = push_index_vector(array, 3, &special);
    int_vector_equal(array, reference);
    free_vector(array);
}

Test(simple_push_index_bigger_index, int_vector)
{
    int *array = init_vector(sizeof(int));
    int tmp[] = {1, 2, 3, 4};
    int soluce[] = {1, 2, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20};
    int special = 20;

    for (int i = 0; i < 4; i++)
        array = push_back_vector(array, &tmp[i]);
    array = push_index_vector(array, 20, &special);
    int_vector_equal(array, soluce);
    free_vector(array);
}

Test(simple_pop_front, int_vector)
{
    int * array = init_vector(sizeof(int));
    int tmp[] = {1, 2, 3};
    int compare[] = {1, 2};

    for (int i = 0; i < 3; i++)
        array = push_back_vector(array, &tmp[i]);
    popfront_vector(array);
    int_vector_equal(array, compare);
    free_vector(array);
}

Test(simple_pop_index, int_vector)
{
    int * array = init_vector(sizeof(int));
    int tmp[] = {1, 2, 3, 4, 5};
    int compare[] = {1, 2, 3, 5};

    for (int i = 0; i < 5; i++)
        array = push_back_vector(array, &tmp[i]);
    pop_index_vector(array, 3);
    int_vector_equal(array, compare);
    free_vector(array);
}

Test(simple_concat, int_vector)
{
    int *first_vector = init_vector(sizeof(int));
    int *second_vector = init_vector(sizeof(int));
    int *final_vector = NULL;
    int first[] = {1, 2, 3};
    int second[] = {4, 5, 6};
    int compare[] = {1, 2, 3, 4, 5, 6};
    int end = '\0';

    for (int i = 0; i < 3; ++i) {
        push_back_vector(first_vector, &first[i]);
        push_back_vector(second_vector, &second[i]);
    }
    push_back_vector(second_vector, &end);
    final_vector = concat_vector(2, first_vector, second_vector);
    int_vector_equal(final_vector, compare);
    free_vector(first_vector);
    free_vector(second_vector);
    free_vector(final_vector);
}

Test(multiple_concat, int_vector)
{
    int *first_vector = init_vector(sizeof(int));
    int *final_vector = NULL;
    int first[] = {1, 2, 3};
    int compare[] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3};

    for (int i = 0; i < 3; ++i) {
        push_back_vector(first_vector, &first[i]);
    }
    final_vector = concat_vector(4, first_vector, first_vector, first_vector, first_vector);
    int_vector_equal(final_vector, compare);
    free_vector(first_vector);
    free_vector(final_vector);
}
