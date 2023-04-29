/*
** EPITECH PROJECT, 2023
** navy
** File description:
** navy
*/

#ifndef NAVY_H_
    #define NAVY_H_

    #include <signal.h>
struct position {
    int col;
    int row;
};
typedef struct navy {
    char **length;
    struct position *begin;
    struct position *end;
}   navy_t;

typedef struct map {
    char **map;
    int row;
    int col;
}   map_t;

void usage(void);

int error(char *filepath);

navy_t get_ship_info(char *filepath);

int manage_2nd_player_input(char *first_pid, char *filepath);

int manage_1st_player_input(char *filepath);

char **display_enemy_map(char *filepath);

char **create_map(char *filepath);

char **first_player_map(char *filepath);

char **second_player_map(char *filepath);

void attack_sig(int signo);

void sig_handler(int signo, siginfo_t *s_info, void *cont);

void enemy_sig(int signo);

void enemy_attack(int signo, siginfo_t *s_info, void *cont);

void checking_position(char *pos, int pid);

void display_player_map(char *filepath, char *str);

char *endgame(char *filepath, char *str);

int finish_game(char *filepath, char *str, int pid);

int check_return(char *player, char *enemy,
                char *player_check, char *enemy_check);

void check_enemy_map(char *filepath, char *pos);

#endif /* !NAVY_H_ */
