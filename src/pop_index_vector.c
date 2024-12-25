/*
** EPITECH PROJECT, 2024
** vector
** File description:
** pop index
*/

#include <stddef.h>
#include <string.h>
#include "vector.h"

void pop_index_vector(void *vector, size_t index)
{
    vector_t *vect = _get_vector_struct(vector);
    char null_value = 0;

    if (vect->stored == 0 || index > vect->stored)
        return;
    memmove(((void *)vect) + sizeof(vector_t) + (index * vect->size),
        ((void *)vect) + sizeof(vector_t) + ((index + 1) * vect->size),
        (vect->stored - (index + 1)) * vect->size);
    for (
        size_t i = (vect->stored - 1) * vect->size;
        i < vect->stored * vect->size;
        i++
        ) {
        memcpy((((void *)vect) + sizeof(vector_t)) + i,
            &null_value, 1);
        }
    vect->stored -=1;
}
