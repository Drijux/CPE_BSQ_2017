/*
* @Author: rjules
* @Date:   2019-09-26 23:08:09
* @Last Modified by:   rjules
* @Last Modified time: 2019-10-07 04:13:49
*/

#ifndef MY_H_
#define MY_H_

#include <string.h>

int my_strlen(const char *);
char *my_strdup(const char *);
int my_getnbr(char *);
void *my_memset(void *, int , size_t );
char *my_strcpy(char *, char const *);

#endif /*MY_H_*/