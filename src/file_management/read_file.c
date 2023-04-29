/*
** EPITECH PROJECT, 2023
** Navy
** File description:
** read files
*/

#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include "./../../include/my.h"
#include "./../../include/navy.h"

char *readfile(char *filepath)
{
    int size = 31;
    char *bf = malloc(sizeof(char) * size + 1);
    int fd = 0, rd = 0;
    fd = open(filepath, O_RDONLY);
    if (fd == -1){
        my_putstr("Please, ensure you put a existing file\n");
        return (NULL);
    }
    rd = read(fd, bf, size);
    bf[rd] = '\0';
    close(fd);

    return (bf);
}

char *read_player_map(char *filepath)
{
    int size = 180;
    char *bf = malloc(sizeof(char) * size + 1);
    int fd = 0, rd = 0;
    fd = open(filepath, O_RDONLY);
    if (fd == -1){
        my_putstr("Please, ensure you put a existing file\n");
        return (NULL);
    }
    rd = read(fd, bf, size);
    bf[rd] = '\0';
    close(fd);

    return (bf);
}

char *rd_atk_file(void)
{
    char *bf = malloc(sizeof(char) * 3);
    int size = 3;
    int fd;
    int rd;
    fd = open("atk_file.txt", O_RDWR);

    rd = read(fd, bf, size);
    bf[rd] = '\0';

    close (fd);
    return (bf);
}

void change_map(map_t map, int r, int c, int a)
{
    for (map.col = 0; map.col < 17; map.col++){
        if (map.row == r && map.col == c){
            map.map[map.row][map.col] = a;
        }
    }
}

char **change_map_file(char *filepath, int r, int c, char a)
{
    int col_len = 17;
    int row_len = 10;
    int size = 180;
    int fd, rd;
    char *bf = malloc(sizeof(char) * size);
    map_t map;
    ssize_t wr;
    fd = open(filepath, O_RDWR);

    rd = read(fd, bf, size);
    bf[rd] = '\0';
    map.map = my_str_to_word_array(bf, '\n');
    for (map.row = 0; map.row < 10; map.row++){
        change_map(map, r, c, a);
    }
    close(fd);
    return (map.map);
}
