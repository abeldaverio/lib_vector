/*
** EPITECH PROJECT, 2024
** vector
** File description:
** push_front
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

void *push_index_vector(void *vector, size_t index, void *data)
{
    vector_t *vect = _get_vector_struct(vector);

    if (vect->stored >= vect->capacity || index >= vect->capacity) {
        vect = resize_vector(vect, vect->capacity * 2);
        if (vect == NULL)
            return NULL;
        return push_index_vector(vect + 1, index, data);
    }
    memmove(((void *)vect) + sizeof(vector_t) + ((index + 1) * vect->size),
        ((void *)vect) + sizeof(vector_t) + (vect->size * index),
        vect->size *
        (vect->stored - (index <= vect->stored ? index : vect->stored)));
    memcpy((((void *)vect) + sizeof(vector_t)) + (vect->size * index),
        data, vect->size);
    vect->stored = index > vect->stored ? index + 1 : vect->stored + 1;
    return vect + 1;
}
