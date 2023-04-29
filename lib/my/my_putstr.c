/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** ...
*/

#include "./../../include/my.h"
#include <unistd.h>

int my_putstr(char const *str)
{
    for (int index = 0; str[index] != '\0'; index++){
        my_putchar(str[index]);
    }
    return (0);
}
