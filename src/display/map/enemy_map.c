/*
** EPITECH PROJECT, 2023
** Navy
** File description:
** function to display the enemy map
*/

#include "./../../../include/navy.h"
#include "./../../../include/my.h"

void change_display(char **map, int row)
{
    char *o = "\033[1;33mo\033[0m";
    char *x = "\033[1;31mx\033[0m";
    char *dot = "\033[1;37m.\033[0m";
    for (int col = 0; col < 17; col++){
        if (map[row][col] >= '2' && map[row][col] <= '5' && col > 0 ||
        map[row][col] == '.'){
            my_putstr(dot);
            continue;
        } if (map[row][col] == 'o'){
            my_putstr(o);
            continue;
        } if (map[row][col] == 'x'){
            my_putstr(x);
            continue;
        }
        my_putchar(map[row][col]);
    }
}

char **display_enemy_map(char *filepath)
{
    char **map = my_str_to_word_array(read_player_map(filepath), '\n');

    my_putstr("\n\033[0;31;4menemy's positions:\033[0m\n");
    for (int row = 0; row < 10; row++){
        change_display(map, row);
        my_putchar('\n');
    }

    return (map);
}

void check_enemy_map(char *filepath, char *pos)
{
    char **map = my_str_to_word_array(read_player_map(filepath), '\n');
    int col = my_getnbr_modified(pos[0]) * 2;
    int row = my_getnbr_modified(pos[1]);

    if (map[row][col] != '.' && map[row][col] != 'o'){
        wr_new_map_file(filepath, row, col, 'x');
        my_putstr(pos);
        my_putstr(": hit\n");
    } else {
        wr_new_map_file(filepath, row, col, 'o');
        my_putstr(pos);
        my_putstr(": missed\n");
    }
}
