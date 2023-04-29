/*
** EPITECH PROJECT, 2023
** navy
** File description:
** manage signals of second player
*/

#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include "./../../include/my.h"
#include "./../../include/navy.h"

void checking_position(char *pos, int pid)
{
    size_t line, size = 10;
    while (1){
        my_putstr("\nAttack: ");
        line = getline(&pos, &size, stdin);
        int len = my_strlen(pos);
        if (!(pos[0] >= 'A' && pos[0] <= 'H') ||
        !(pos[1] >= '1' && pos[1] <= '8') || len > 3){
            my_putstr("Wrong position\n");
            continue;
        } if (pos[0] >= 'A' && pos[0] <= 'H' ||
        pos[1] >= '1' && pos[1] <= '8') {
            wr_atk_file(pos);
            check_enemy_map("first_player.txt", pos);
            kill(pid, SIGUSR2);
            break;

        }
    }
}

int illimitable_loop(char *filepath, int pid)
{
    int n = -1;
    char *player = "\nI won\n", *enemy = "\nEnemy won\n";
    char *player_check = NULL, *enemy_check = NULL;
    while (1){
        pause();
        enemy_check = endgame("second_player.txt", enemy);
        n = check_return(player, enemy, player_check, enemy_check);
        if (n == 1 || n == 0)
            break;
        display_player_map("second_player.txt", "I won!");
        player_check = endgame("first_player.txt", player);
        n = check_return(player, enemy, player_check, enemy_check);
        if (n == 1 || n == 0)
            break;
        display_enemy_map("first_player.txt");
        usleep(1000000);
        my_putstr("\n\033[38;5;208mwaiting for enemy's attack...\033[0m\n");
    }

    return (n);
}

void sig_connection(void)
{
    struct sigaction sig;
    sig.sa_sigaction = enemy_attack;
    sigemptyset(&sig.sa_mask);
    sig.sa_flags = SA_SIGINFO;
    if (sigaction(SIGUSR2, &sig, NULL) == -1){
        my_putstr("Enemy couldn't connect\n");
    }
}

int manage_2nd_player_input(char *first_pid, char *filepath)
{
    int pid = my_getnbr(first_pid);
    int my_pid = getpid();
    int n = -1;

    if (my_strcmp(filepath, "pos2") == 0 && pid > 0){
        second_player_map(filepath);
        my_putstr("my_pid: ");
        my_put_nbr(my_pid);
        my_putchar('\n');
        kill(pid, SIGUSR1);
        if (signal(SIGUSR1, enemy_sig) == SIG_ERR){
            my_putstr("player couldn't sent signal to enemy\n");
        }
        sig_connection();
        n = illimitable_loop(filepath, my_pid);
    }
    return (n);
}
