/*
** EPITECH PROJECT, 2024
** vector
** File description:
** concat vector
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <string.h>
#include "vector.h"
#include <stdio.h>

static void **get_parameter_vectors(int nb_of_vectors, va_list parameters_infos)
{
    void **vectors = calloc((nb_of_vectors + 1), sizeof(void *));
    int i = 0;

    if (vectors == NULL)
        return NULL;
    while (i < nb_of_vectors) {
        vectors[i] = (void *)(va_arg(parameters_infos, void *));
        ++i;
    }
    return vectors;
}

static void *concat_one(void *base, void *to_concat) {
    vector_t *base_struct = _get_vector_struct(base);
    vector_t *to_concat_struct = _get_vector_struct(to_concat);

    if (base_struct->capacity <
        base_struct->stored + to_concat_struct->stored) {
        base_struct = resize_vector(base_struct, base_struct->capacity * 2);
        if (base_struct == NULL)
            return NULL;
        return concat_one(base_struct + 1, to_concat);
    }
    memcpy(base + (base_struct->size * (base_struct->stored)),
        to_concat, to_concat_struct->size * to_concat_struct->stored);
    base_struct->stored += to_concat_struct->stored;
    return base;
}

static void *get_concat_vector(void **vectors) {
    vector_t *reference = _get_vector_struct(vectors[0]);
    void *new_vector = init_vector(reference->size);

    for (int i = 0; vectors[i]; ++i) {
        new_vector = concat_one(new_vector, vectors[i]);
    }
    free(vectors);
    return new_vector;
}

// assuming the vectors are the same type
void *concat_vector(int nb_of_vectors, ...)
{
    va_list parameters_infos;
    void **vectors = NULL;

    if (nb_of_vectors <= 0)
        return NULL;
    va_start(parameters_infos, nb_of_vectors);
    vectors = get_parameter_vectors(nb_of_vectors, parameters_infos);
    va_end(parameters_infos);
    return get_concat_vector(vectors);
}
