/*
** EPITECH PROJECT, 2023
** navy
** File description:
** navy
*/

#include <fcntl.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "./../../include/my.h"
#include "./../../include/navy.h"

int main(int argc, char **argv)
{
    int n = -1;
    if (argc == 1 || argc > 3){
        my_putstr("Please, check the '-h' to know how to run the program\n");
        return (84);
    }
    if (my_strcmp(argv[1], "-h") == 0){
        usage();
    } else if (argc == 3){
        n = manage_2nd_player_input(argv[1], argv[2]);
    } else {
        if (error(argv[1]) == 84)
            return (84);
        n = manage_1st_player_input(argv[1]);
    }

    return (n);
}
