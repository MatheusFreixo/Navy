/*
** EPITECH PROJECT, 2023
** navy
** File description:
** signal handler functions
*/

#include <signal.h>
#include "./../../../include/my.h"
#include "./../../../include/navy.h"

int enemy_pid = 0;

void attack_sig(int signo)
{
    char *bf = rd_atk_file();
    int col = my_getnbr_modified(bf[0]) * 2;
    int row = my_getnbr_modified(bf[1]);
    char **map;
    map = my_str_to_word_array(read_player_map("first_player.txt"), '\n');
    if (signo == SIGUSR2){
        if (map[row][col] != '.' && map[row][col] != 'o'){
            wr_new_map_file("first_player.txt", row, col, 'x');
            my_putstr(bf);
            my_putstr(": hit\n");
        } else {
            wr_new_map_file("first_player.txt", row, col, 'o');
            my_putstr(bf);
            my_putstr(": missed\n");
        }
    }
}

void sig_handler(int signo, siginfo_t *s_info, void *cont)
{
    enemy_pid = s_info->si_pid;
    if (signo == SIGUSR1){
        my_putstr("Enemy connected\n");
        kill(enemy_pid, SIGUSR1);
    }
}

void enemy_sig(int signo)
{
    if (signo == SIGUSR1){
        my_putstr("successfully connected\n");
    }
}

void check_map(map_t map, char *pos, char *bf, int pid)
{
    size_t line, size = 10;
    if (map.map[map.row][map.col] != '.'){
        wr_new_map_file("second_player.txt", map.row, map.col, 'x');
        my_putstr(bf);
        my_putstr("hit!\n");
        checking_position(pos, pid);
    } else {
        wr_new_map_file("second_player.txt", map.row, map.col, 'o');
        my_putstr(bf);
        my_putstr("missed!\n");
        checking_position(pos, pid);
    }
}

void enemy_attack(int signo, siginfo_t *s_info, void *cont)
{
    map_t map;
    size_t size = 10;
    char *pos = malloc(sizeof(char) * size), *bf = rd_atk_file();
    int pid = s_info->si_pid;
    map.col = my_getnbr_modified(bf[0]) * 2;
    map.row = my_getnbr_modified(bf[1]);
    map.map = my_str_to_word_array(read_player_map("second_player.txt"), '\n');
    if (signo == SIGUSR2){
        check_map(map, pos, bf, pid);
    }
}
