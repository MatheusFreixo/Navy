/*
** EPITECH PROJECT, 2023
** navy
** File description:
** file containing the usage display when put '-h' as a parameter
*/

#include "./../../include/my.h"

void usage(void)
{
    my_putstr("USAGE:\n");
    my_putstr("\t./navy [first_player_pid] navy_positions\n\n");
    my_putstr("DESCRIPTION:\n");
    my_putstr("\tfirst_player_pid: only for the 2nd player.");
    my_putstr(" pid of the first player.\n");
    my_putstr("\tnavy_positions:");
    my_putstr(" file representing the positions of the ships.\n");
}
