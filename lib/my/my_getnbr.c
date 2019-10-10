/*
* @Author: rjules
* @Date:   2019-10-07 03:43:24
* @Last Modified by:   rjules
* @Last Modified time: 2019-10-07 03:49:34
*/

int my_getnbr(char *str)
{
	int nb = 0;
	int sign = 1;
	int i = 0;

	for (;(str[i] == '-' || str[i] == '+')
	|| (str[i] < '0' && str[i] > '9'); ++i) {
		if (str[i] == '-')
			sign = sign * -1;
	}
	for (;(str[i] >= '0' && str[i] <= '9') || str[i] == ' '; ++i)
		nb = nb * 10 + str[i] - '0';
	return (nb * sign);
}