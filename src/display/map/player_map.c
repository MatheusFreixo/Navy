/*
** EPITECH PROJECT, 2023
** Navy
** File description:
** functions to display the enemy map
*/

#include "./../../../include/navy.h"
#include "./../../../include/my.h"

void display_ship_length(char **map, navy_t ship, int i, int row)
{
    for (int col = 0; map[row][col] != '\0'; col++){
        if (col == ship.begin[i].col && row == ship.begin[i].row){
            map[row][col] = ship.length[i][0];
        } if (col == ship.end[i].col && row == ship.end[i].row){
            map[row][col] = ship.length[i][0];
        }
    }
}

void fill_ship(char **map, int row)
{
    for (int col = 0; map[row][col] != '\0'; col++){
        if (map[row][col] == '3' && map[row][col + 4] == '3')
            map[row][col + 2] = '3';
        if (map[row][col] == '3' && map[row + 2][col] == '3')
            map[row + 1][col] = '3';
        if (map[row][col] == '4' && map[row][col + 6] == '4')
            (map[row][col + 2] = '4') && (map[row][col + 4] = '4');
        if (map[row][col] == '4' && map[row + 3][col] == '4')
            (map[row + 1][col] = '4') && (map[row + 2][col] = '4');
        if (map[row][col] == '5' && map[row][col + 8] == '5'){
            map[row][col + 2] = '5';
            map[row][col + 4] = '5';
            map[row][col + 6] = '5';
        }
        if (map[row][col] == '5' && map[row + 4][col] == '5'){
            map[row + 1][col] = '5';
            map[row + 2][col] = '5';
            map[row + 3][col] = '5';
        }
    }
}

char **first_player_map(char *filepath)
{
    char **map = create_map(filepath);
    navy_t ship = get_ship_info(filepath);
    int count = 0;
    char **player_map;

    for (int i = 0; i < 4; i++){
        for (int row = 0; map[row] != NULL; row++){
            display_ship_length(map, ship, i, row);
        }
    }
    for (int row = 0; map[row] != NULL; row++){
        fill_ship(map, row);
    }
    writefile(map, "first_player.txt");

    return (map);
}

char **second_player_map(char *filepath)
{
    char **map = create_map(filepath);
    navy_t ship = get_ship_info(filepath);
    char **player_map;

    for (int i = 0; i < 4; i++){
        for (int row = 0; map[row] != NULL; row++){
            display_ship_length(map, ship, i, row);
        }
    }
    for (int row = 0; map[row] != NULL; row++){
        fill_ship(map, row);
    }
    writefile(map, "second_player.txt");
    return (map);
}

void display_player_map(char *filepath, char *str)
{
    char *map = read_player_map(filepath);
    int size = my_strlen(map);
    char *o = "\033[1;33mo\033[0m";
    char *x = "\033[1;31mx\033[0m";
    char *dot = "\033[1;37m.\033[0m";

    my_putstr("\n\033[38;5;135;4mmy positions:\033[0m\n");
    for (int i = 0; i < size; i++){
        if (map[i] == 'x'){
            my_putstr(x);
            continue;
        } if (map[i] == 'o'){
            my_putstr(o);
            continue;
        } if (map[i] == '.'){
            my_putstr(dot);
            continue;
        }
        my_putchar(map[i]);
    }
}
