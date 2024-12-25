/*
** EPITECH PROJECT, 2024
** vector
** File description:
**
*/

#include <stddef.h>
#include "vector.h"

size_t vector_size(void *vector)
{
    vector_t *vect = _get_vector_struct(vector);

    return vect->stored;
}
