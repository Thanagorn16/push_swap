#include "push_swap.h"

int check_digit(char **str) // check while the arguments are still strings
{
    int i;
    int j;
    char    *temp;

    i = 0;
    j = 0;
    temp = str[i];
    while (str[i])
    {
        j = 0;
        while (str[i][j] >= '0' && str[i][j] <= '9' || str[i][j] == '-' || str[i][j] == '+')
            j++;
        if (str[i][j] != '\0' && str[i][j] < '0' || str[i][j] > '9' && str[i][j] != '-' && str[i][j] != '+')
            return (-1);
        i++;
    }
    return (0);
}