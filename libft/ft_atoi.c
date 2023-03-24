#include "libft.h"

long long	ft_atoi(const char *str)
{
	long long	temp;
	int	nev;
	int	i;

	i = 0;
	nev = 0;
	temp = 0;
	// printf("atoi:%s\n", str);
	while (str[i] == '+' || str[i] == '-') // check if there's a set of operators before the digit
	{
		i++;
		if (i > 1)
			is_err();
	}
	i = 0;
	if (str[i] != '\0' && str[i] == '-') //check negative
	{
		nev = 1;
		i++;
	}
	else if (str[i] == '+') //skip + operator
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') //convert to integer
		temp = (temp * 10) + (str[i++] - '0');
	if (str[i] == '+' || str[i] == '-') //check if there's operator after the digit
		is_err();
	if (nev == 1) //convert to nev
		return (-temp);
	// printf("temp:%lld\n", temp);
	return (temp);
}