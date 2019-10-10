/*
* @Author: rjules
* @Date:   2019-10-05 11:10:12
* @Last Modified by:   rjules
* @Last Modified time: 2019-10-10 21:53:48
*/

#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"
#include "my.h"

static void find_square(info_t *info)
{
    int cols = info->cols;

    for (int i = cols; i < info->size; ++i) {
        if (i % cols != 0 && info->map_int[i] > 0) {
            if (info->map_int[i - 1] <= info->map_int[i - cols - 1]
                && info->map_int[i - 1] <= info->map_int[i - cols])
                info->map_int[i] = info->map_int[i - 1] + 1;
            if (info->map_int[i - cols] <= info->map_int[i - cols - 1]
                && info->map_int[i - cols] <= info->map_int[i - 1])
                info->map_int[i] = info->map_int[i - cols] + 1;
            if (info->map_int[i - cols - 1] <= info->map_int[i - cols]
                && info->map_int[i - cols - 1] <= info->map_int[i - 1])
                info->map_int[i] = info->map_int[i - cols - 1] + 1;
            if (info->map_int[i] > info->stock) {
                info->index = i;
                info->stock = info->map_int[i];
            }
        }
    }
}

static bool fill_map(info_t *info)
{
    info->map_int = malloc(sizeof(int) * info->size);
    info->map_str = malloc(sizeof(char) * info->size);
    read(info->fd, info->map_str, info->size);
    if (info->map_int == NULL || info->map_str == NULL)
        return (false);
    for (int i = 0; i < info->size; ++i) {
        if (info->map_str[i] == '.') {
            info->map_int[i] = 1;
            if (info->map_int[i] > info->stock) {
                info->stock = info->map_int[i];
                info->index = i;
            }
        }
        else if (info->map_str[i] == 'o')
            info->map_int[i] = 0;
        else
            info->map_int[i] = -1;
    }
    return (true);
}

static bool check_file(info_t *info)
{
    char buff[11];
    int i = 0;

    my_memset(buff, 0, 10);
    do {
        read(info->fd, buff + i, 1);
        ++i;
    }
    while (buff[i - 1] != '\n');
    info->size -= my_strlen(buff);
    info->line = my_getnbr(buff);
    info->cols =  info->size / info->line;
    if (info->line < 1 || !fill_map(info))
        return (false);
    return (true);
}

static bool check_av(char *path, info_t *info)
{
    struct stat map;

    info->fd = open(path, O_RDONLY);
    if (info->fd == -1)
        return (false);
    stat(path, &map);
    info->size = map.st_size;
    info->index = 0;
    info->stock = 0;
    if (!check_file(info))
        return (false);
    close(info->fd);
    return (true);
}

int main(int ac, char **av)
{
    info_t info;

    if (ac != 2 || !check_av(av[1], &info))
        return (FAILURE);
    find_square(&info);
    for (int x = info.index, i = info.stock; i > 0; x = x - info.cols, i--) {
        for (int l = 0; l < info.stock; l++)
            info.map_str[x - l] = 'x';
    }
    write(1, info.map_str, info.size);
    free(info.map_int);
    free(info.map_str);
    return (SUCCESS);
}