/*
** EPITECH PROJECT, 2017
** my_strcpy.c
** File description:
** For lib: function for cpy a string in other
*/

char *my_strcpy(char *dest, char const *src)
{
	int i = 0;

	for (; src[i]; ++i)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
