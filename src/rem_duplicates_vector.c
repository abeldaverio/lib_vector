/*
** EPITECH PROJECT, 2024
** vector
** File description:
** remove duplicates
*/

#include <stddef.h>
#include "vector.h"

void *rem_duplicates_vector(void *vector)
{
    vector_t *vect = _get_vector_struct(vector);
    void *new_vector = init_vector(vect->size);

    for (size_t i = 0; i < vect->stored && new_vector; ++i) {
        if (index_of_vector(new_vector, vector + (i * vect->size)) == -1)
            new_vector = push_back_vector(
                new_vector, vector + (i * vect->size));
    }
    return new_vector;
}
