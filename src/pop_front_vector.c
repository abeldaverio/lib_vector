/*
** EPITECH PROJECT, 2024
** vector
** File description:
** pop_front
*/

#include <stddef.h>
#include <string.h>
#include "vector.h"

void popfront_vector(void *vector)
{
    vector_t *vect = _get_vector_struct(vector);
    char null_value = 0;

    if (vect->stored == 0)
        return;
    memmove(((void *)vect) + sizeof(vector_t),
        ((void *)vect) + sizeof(vector_t) + vect->size,
        (vect->stored - 1) * vect->size);
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
