/*
** EPITECH PROJECT, 2024
** vector
** File description:
** init vector
*/

#include <stddef.h>
#include <stdlib.h>
#include "vector.h"

void *init_vector(size_t size)
{
    vector_t *vect = calloc(sizeof(vector_t) + (size * INIT_SIZE), 1);

    if (vect == NULL)
        return NULL;
    vect->capacity = INIT_SIZE;
    vect->stored = 0;
    vect->size = size;
    return (void *)(vect + 1);
}
