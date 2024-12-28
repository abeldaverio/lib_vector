/*
** EPITECH PROJECT, 2024
** vector
** File description:
** quick sort
*/

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "vector.h"


static int partition(vector_t *vect, int low, int high,
    int (*function)(void *first, void *second))
{
    void *vector = vect + 1;
    void *pivot = vector + (low * vect->size);
    int i = low;
    int j = high;

    while (i < j) {
            while (function(vector + (i * vect->size), pivot) >= 0 && i <= high - 1)
                i++;
            while (function(vector + (j * vect->size), pivot) < 0 && j >= low + 1)
                j--;
            if (i < j) {
                swap_vector_element(vect, i, j);
            }
        }
        swap_vector_element(vect, low, j);
        return j;
}

static bool execute_sort(vector_t *vect, int low, int high,
    int (*function)(void *first, void *second))
{
    int pi = partition(vect, low, high, function);
    if (pi == -1)
        return false;
    if (!_sort(vect, low, pi - 1, function) ||
        !_sort(vect, pi + 1, high, function))
        return false;
    return true;
}

bool _sort(vector_t *vect, int low, int high,
    int (*function)(void *first, void *second))
{
    if ((low >= high))
        return true;
    return execute_sort(vect, low, high, function);
}

void quick_sort_vector(void *vector,
    int (*function)(void *first, void *second))
{
    vector_t *vect = _get_vector_struct(vector);

    _sort(vect, 0, vect->stored - 1, function);
}
