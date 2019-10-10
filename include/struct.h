/*
* @Author: rjules
* @Date:   2019-10-05 11:10:48
* @Last Modified by:   rjules
* @Last Modified time: 2019-10-10 10:35:41
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <stdbool.h>

typedef struct info {
    int line;
    int cols;
    int index;
    int stock;
    int fd;
    int size;
    char *map_str;
    int *map_int;
} info_t;

#define SUCCESS 0
#define FAILURE 84


#endif /* STRUCT_H_ */