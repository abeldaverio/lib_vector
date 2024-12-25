/*
** EPITECH PROJECT, 2024
** vector
** File description:
** main
*/

#include <stdio.h>
#include "include/vector.h"

int main()
{
    int *array = init_vector(sizeof(int));
    int *array2 = init_vector(sizeof(int));
    int added = 10;
    int removed = 3;

    printf("%d\n", sizeof(vector_t));
    for (int i = 0; i < added; i++) {
        array = push_back_vector(array, &i);
        array2 = push_back_vector(array2, &i);
    }
    int *test = concat_vector(3, array, array2, array);
    free_vector(test);
    free_vector(array2);
    free_vector(array);
}
