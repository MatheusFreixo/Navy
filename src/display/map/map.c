/*
** EPITECH PROJECT, 2023
** Navy
** File description:
** File where manage the map
*/

#include <stdio.h>
#include <stdlib.h>
#include "./../../../include/navy.h"
#include "./../../../include/my.h"

void fill_map(char **map, int row)
{
    for (int col = 0; col < 17; col++){
        if (col == 0){
            map[row][col] = row + 47;
            continue;
        } if (col == 1){
            map[row][col] = '|';
            continue;
        } if (col == 3 || col == 5 || col == 7 || col == 9 || col == 11 ||
        col == 13 || col == 15){
            map[row][col] = ' ';
            continue;
        }
        map[row][col] = '.';
    }
}

char **create_map(char *filepath)
{
    navy_t ship = get_ship_info(filepath);
    char **map = malloc(sizeof(char*) * 10 + 1);
    for (int i = 0; i < 18; i++){
        map[i] = malloc(sizeof(char) * 17 + 1);
    }
    map[0] = " |A B C D E F G H";
    map[1] = "-+---------------";
    for (int row = 2; row < 10; row++){
        fill_map(map, row);
    }

    return (map);
}
