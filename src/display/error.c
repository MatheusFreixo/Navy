/*
** EPITECH PROJECT, 2023
** navy
** File description:
** file containing the error messages as a parameter
*/

#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include "./../../include/my.h"

int error(char *filepath)
{
    int size = 31;
    char *bf = malloc(sizeof(char) * 31 + 1);
    int fd = open(filepath, O_RDONLY);
    int rd = read(fd, bf, 31);
    if (fd == -1 || rd == 0){
        my_putstr("Please, ensure you put an existing file");
        my_putstr(" or if your file isn't empty\n");
        return (84);
    }
    if (bf[0] != '2' || bf[8] != '3' || bf[16] != '4' || bf[24] != '5' ||
    bf[1] != ':' || bf[9] != ':' || bf[17] != ':' || bf[25] != ':' ||
    bf[4] != ':' || bf[12] != ':' || bf[20] != ':' || bf[28] != ':'){
        my_putstr("Please, ensure your file is written");
        my_putstr(" in the correct format\n");
        return (84);
    }
    return (0);
}
