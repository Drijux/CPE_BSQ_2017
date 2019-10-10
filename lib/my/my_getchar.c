/*
* @Author: rjules
* @Date:   2019-10-07 04:19:42
* @Last Modified by:   rjules
* @Last Modified time: 2019-10-07 04:19:54
*/

#include <stdbool.h>

bool my_getchar(const char *str, const char to_find)
{
    for (int i = 0; str[i]; ++i) {
        if (str[i] == to_find)
            return (true);
    }
    return (false);
}