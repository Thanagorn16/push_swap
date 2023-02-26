#include "libft.h"

int	ft_atoi(const char *str)
{
	int	temp;
	int	nev;
	int	i;

	i = 0;
	nev = 0;
	temp = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' 
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')) // skip spaces
		i++;
	if (str[i] != '\0' && str[i] == '-') //check negative
	{
		nev = 1;
		i++;
	}
	else if (str[i] == '+') //skip + operator
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') //convert to integer
		temp = (temp * 10) + (str[i++] - '0');
	if (nev == 1) //convert to nev
		return (-temp);
	return (temp);
}