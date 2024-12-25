/*
** EPITECH PROJECT, 2024
** vector
** File description:
** free vector
*/

#include <stdlib.h>
#include "vector.h"

void free_vector(void *vector)
{
    free(_get_vector_struct(vector));
}
