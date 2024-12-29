/*
** EPITECH PROJECT, 2024
** vector
** File description:
** compare bytes
*/

#include <stddef.h>
#include <stdbool.h>

bool _compare_bytes(char *first, char *second, size_t n)
{
    for (size_t i = 0; i < n; ++i)
        if (first[i] != second[i])
            return false;
    return true;
}
