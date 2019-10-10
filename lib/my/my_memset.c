/*
* @Author: rjules
* @Date:   2019-09-29 19:11:33
* @Last Modified by:   rjules
* @Last Modified time: 2019-09-29 19:12:45
*/

#include <string.h>

void *my_memset(void *s, int c, size_t n)
{
    char *save = (char *)s;

    for (size_t i = 0; i < n; ++i)
        save[i] = (char)c;
    return (save);
}