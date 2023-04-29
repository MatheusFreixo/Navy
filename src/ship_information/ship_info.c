/*
** EPITECH PROJECT, 2023
** navy
** File description:
** File where contains the functions that get all the ship information
*/

#include <stdio.h>
#include "./../../include/my.h"
#include "./../../include/navy.h"

char **ship_length(char ***arr_arr)
{
    char **length = malloc(sizeof(char*) * 4 + 1);
    for (int i = 0; i < 4; i++){
        length[i] = arr_arr[i][0];
    }
    return (length);
}

char ***divide_info(char **arr, int count)
{
    char ***arr_arr = malloc(sizeof(char**) * count + 1 + 1);
    for (int i = 0; arr[i] != NULL; i++){
        arr_arr[i] = my_str_to_word_array(arr[i], ':');
    }
    return (arr_arr);
}

struct position *get_begin_pos(char ***arr_arr)
{
    struct position *begin = malloc(sizeof(struct position) * 4 + 1);

    for (int i = 0; i < 4; i++){
        begin[i].col = (my_getnbr_modified(arr_arr[i][1][0]) * 2);
        begin[i].row = my_getnbr_modified(arr_arr[i][1][1]);
    }
    return (begin);
}

struct position *get_end_pos(char ***arr_arr)
{
    struct position *end = malloc(sizeof(struct position) * 4 + 1);

    for (int i = 0; i < 4; i++){
        end[i].col = (my_getnbr_modified(arr_arr[i][2][0]) * 2);
        end[i].row = my_getnbr_modified(arr_arr[i][2][1]);
    }
    return (end);
}

navy_t get_ship_info(char *filepath)
{
    navy_t ship;
    char *str = readfile(filepath);
    char **arr = my_str_to_word_array(str, '\n');
    char ***arr_arr = NULL;
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == ':' || str[i] == '\n'){
            count++;
        }
    }
    arr_arr = divide_info(arr, count);
    ship.begin = get_begin_pos(arr_arr);
    ship.end = get_end_pos(arr_arr);
    ship.length = ship_length(arr_arr);

    return (ship);
}
