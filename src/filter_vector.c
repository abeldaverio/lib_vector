/*
** EPITECH PROJECT, 2024
** vector
** File description:
** filter vector
*/

#include <stddef.h>
#include <stdbool.h>
#include <stddef.h>
#include "vector.h"

void *filter_vector(void *vector, bool (*function)(void *value))
{
    vector_t *vect = _get_vector_struct(vector);
    void *new_vector = init_vector(vect->size);

    if (!new_vector)
        return  NULL;
    for (size_t i = 0; i < vect->stored && new_vector; ++i) {
        if (function(vector + (i * vect->size)))
            new_vector = push_back_vector(new_vector, vector + (i * vect->size));
    }
    return new_vector;
}
