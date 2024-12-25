/*
** EPITECH PROJECT, 2024
** include
** File description:
** vectors
*/

#pragma once

#include <stddef.h>
#include <stdarg.h>

typedef struct vector_s {
    size_t capacity;
    size_t stored;
    size_t size;
}vector_t;

// functions
void *init_vector(size_t size);
void free_vector(void *vector);
void *push_back_vector(void *vector, void *data);
vector_t *resize_vector(vector_t *vector, size_t new_size);
void popback_vector(void *vector);
size_t vector_size(void *vector);
void *push_front_vector(void *vector, void *data);
void *push_index_vector(void *vector, size_t index, void *data);
void popfront_vector(void *vector);
void pop_index_vector(void *vector, size_t index);
void *concat_vector(int nb_of_vectors, ...);

// internal used functions
vector_t *_get_vector_struct(void *vector);

static const size_t INIT_SIZE = 5;