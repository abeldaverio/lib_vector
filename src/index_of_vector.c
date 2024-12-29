/*
** EPITECH PROJECT, 2024
** vector
** File description:
** index of
*/

#include <stddef.h>
#include <unistd.h>
#include "vector.h"

ssize_t index_of_vector(void *vector, void *to_find)
{
    vector_t *vect = _get_vector_struct(vector);

    for (size_t i = 0; i < vect->stored; ++i) {
        if (_compare_bytes(vector + (i * vect->size), to_find, vect->size))
            return i;
    }
    return -1;
}
