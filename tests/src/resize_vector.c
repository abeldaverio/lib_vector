/*
** EPITECH PROJECT, 2024
** vector
** File description:
** resize
*/

#include <stdlib.h>
#include <string.h>
#include "vector.h"

vector_t *resize_vector(vector_t *vector, size_t new_size)
{
    size_t old_capacity = vector->capacity;
    char null_value = 0;

    vector = realloc(vector, sizeof(vector_t) + new_size * vector->size);
    if (vector == NULL)
        return NULL;
    vector->capacity = new_size;
    for (
        size_t i = old_capacity * vector->size;
        i < vector->capacity * vector->size;
        i++
        )
        memcpy(((void *)vector + sizeof(vector_t)) + i,
            &null_value, 1);
    return vector;
}