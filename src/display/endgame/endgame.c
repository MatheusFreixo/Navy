/*
** EPITECH PROJECT, 2023
** navy
** File description:
** Functions to end the program
*/

#include "./../../../include/my.h"
#include "./../../../include/navy.h"

char *endgame(char *filepath, char *str)
{
    char *ret = NULL;
    char *map = read_player_map(filepath);
    int size = my_strlen(map);
    char *o = "\033[1;33mo\033[0m";
    char *x = "\033[1;31mx\033[0m";
    int count = 0;
    for (int i = 0; i < size; i++){
        if (map[i] == 'x'){
            count++;
        }
    }
    if (count == 14){
        my_putstr(str);
        ret = str;
    }
    return (ret);
}

int finish_game(char *filepath, char *str, int pid)
{
    char *player = "\nI won\n";
    char *enemy = "\nEnemy won\n";
    int n = 5;
    char *end = endgame(filepath, str);
    extern int enemy_pid;
    if (end == str && my_strcmp(str, player) == 0){
        n = 0;
    }
    if (end == str && my_strcmp(str, enemy) == 0){
        n = 1;
    }
    return (n);
}

int check_return(char *player, char *enemy,
                char *player_check, char *enemy_check)
{
    int n = -1;

    if (player_check == player){
        n = 0;
    } else if (enemy_check == enemy){
        n = 1;
    }

    return (n);
}
