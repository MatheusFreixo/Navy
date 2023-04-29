/*
** EPITECH PROJECT, 2023
** Navy
** File description:
** write files
*/

#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include "./../../include/my.h"

int writefile(char **arr, char *filepath)
{
    int size = 17;
    int fd;
    ssize_t wr;
    fd = open(filepath, O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);

    for (int i = 0; i < 10; i++){
        write(fd, arr[i], size);
        write(fd, "\n", 1);
    }
    close (fd);
    return (fd);
}

int wr_atk_file(char *bf)
{
    int size = 3;
    int fd;
    ssize_t wr;
    fd = open("atk_file.txt", O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);

    wr = write(fd, bf, size);
    bf[2] = '\0';

    close (fd);
    return (fd);
}

int wr_new_map_file(char *filepath, int r, int c, char a)
{
    int col_len = 17;
    int row_len = 10;
    int size = 180;
    int fd, rd;
    char *bf = malloc(sizeof(char) * size);
    char **map = change_map_file(filepath, r, c, a);
    ssize_t wr;
    fd = open(filepath, O_RDWR);

    for (int i = 0; i < 10; i++){
        wr = write(fd, map[i], col_len);
        bf[wr] = '\0';
        write(fd, "\n", 1);
    }

    close (fd);
    return (fd);
}
