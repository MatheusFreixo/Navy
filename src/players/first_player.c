/*
** EPITECH PROJECT, 2023
** navy
** File description:
** manage signals of first player
*/

#include <signal.h>
#include <unistd.h>
#include "./../../include/my.h"
#include "./../../include/navy.h"

void signal_connection(void)
{
    struct sigaction sig;
    sig.sa_sigaction = sig_handler;
    sigemptyset(&sig.sa_mask);
    sig.sa_flags = SA_SIGINFO;
    if (sigaction(SIGUSR1, &sig, NULL) == -1){
        my_putstr("Enemy couldn't connect\n");
    }
}

void check_position(int pid)
{
    size_t size = 10, line;
    char *pos = malloc(sizeof(char) * size);
    extern int enemy_pid;
    while (1){
        my_putstr("\nattack: ");
        line = getline(&pos, &size, stdin);
        int len = my_strlen(pos);
        if (!(pos[0] >= 'A' && pos[0] <= 'H') ||
        !(pos[1] >= '1' && pos[1] <= '8') || len > 3){
            my_putstr("Wrong position\n");
            continue;
        } if (pos[0] >= 'A' && pos[0] <= 'H' ||
        pos[1] >= '1' && pos[1] <= '8') {
            wr_atk_file(pos);
            check_enemy_map("second_player.txt", pos);
            my_putstr("\n\033[38;5;208mwaiting for enemy's attack...\033[0m\n");
            kill(enemy_pid, SIGUSR2);
            break;
        }
    }
}

int infinite_loop(char *filepath, int pid)
{
    int n = -1;
    char *player = "\nI won\n", *enemy = "\nEnemy won\n";
    char *player_check = NULL, *enemy_check = NULL;
    while (1){
        pause();
        player_check = endgame("second_player.txt", player);
        enemy_check = endgame("first_player.txt", enemy);
        n = check_return(player, enemy, player_check, enemy_check);
        if (n == 1 || n == 0)
            break;
        display_player_map("first_player.txt", "I won!");
        display_enemy_map("second_player.txt");
        usleep(1000000);
        check_position(pid);
        signal(SIGUSR2, attack_sig);
    } return (n);
}

int manage_1st_player_input(char *filepath)
{
    int pid = getpid();
    int n = -1;
    if (my_strcmp(filepath, "pos1") == 0){
        first_player_map(filepath);
        my_putstr("my_pid: ");
        my_put_nbr(pid);
        my_putstr("\nwaiting for enemy connection...\n\n");
        signal_connection();
        n = infinite_loop(filepath, pid);
    }
    return (n);
}
