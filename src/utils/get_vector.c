/*
** EPITECH PROJECT, 2024
** vector
** File description:
** init vector
*/

#include "vector.h"

vector_t * _get_vector_struct(void *vector) {
    return vector - sizeof(vector_t);
}
