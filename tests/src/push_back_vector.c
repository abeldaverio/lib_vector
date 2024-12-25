/*
** EPITECH PROJECT, 2024
** vector
** File description:
** push_back
*/

#include <stdlib.h>
#include <string.h>
#include "vector.h"

void *push_back_vector(void *vector, void *data)
{
    vector_t *vect = _get_vector_struct(vector);

    if (vect->stored >= vect->capacity) {
        vect = resize_vector(vect, vect->capacity * 2);
        if (vect == NULL)
            return NULL;
        return push_back_vector(vect + 1, data);
    }
    memcpy((((void *)vect) + sizeof(vector_t)) +
           (vect->size * (vect->stored)), data, vect->size);
    vect->stored += 1;
    return vect + 1;
}
