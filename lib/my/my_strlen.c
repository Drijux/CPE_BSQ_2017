/*
** EPITECH PROJECT, 2017
** MY_STRLEN.C (FOR LIB)
** File description:
** Function for count the caractere on string
*/

#include <unistd.h>

int my_strlen(char const *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	for (;str[i] != '\0'; ++i);
	return (i);
}