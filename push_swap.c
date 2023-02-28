#include "push_swap.h"

char    **create_double(char **av)
{
    int i;
    int j;
    int count;
    char    **temp;
    char    **set;

    i = 1;
    j = 0;
    count = 0;
    while (av[i]) // big malloc // this method check all the arguments at once that's why 2d array is made
    {
        j = 0;
        temp = ft_split(av[i], ' ');
        while (temp[j] != NULL)
        {
            j++;
            count++; //count the set of numbers after split
        }
        i++;
    }
    set = (char **)malloc(sizeof(char *) * count);
    if (!set)
        return (NULL);
    return (set);
}

int main(int ac, char **av)
{
    int i;
    int j;
    int k;
    int len;
    char    **set;
    char    **temp;
    char    *str;

    if (ac < 2)
        return (0);

// check arguments
    set = create_double(av);
    i = 1;
    j = 0;
    while (av[i])
    {
        k = 0;
        if (av[i]) //split
            temp = ft_split(av[i], ' ');
        while (temp[k] != NULL) // copy the splitted nums to malloc
        {
            str = ft_strdup(temp[k]);
            set[j] = (char *)malloc(sizeof(char) * ft_strlen(str) + 1); // small malloc
            if (!set[j])
                return (NULL);
            len = 0;
            while (str[len]) 
            {
                set[j][len] = str[len];
                len++;
            }
            set[j][len] = '\0';
            j++;
            k++; // this is used to get out of the loop
        }
        i++;
    }
    set[j] = NULL; // set the end of the array
    i = 0;
    while (set[i])
        printf("set:%s\n", set[i++]);
    // new_args = ft_strdup(av[i++]);
    // while (av[i])
    //     new_args = ft_strjoin(new_args, av[i++]);
    // // discard spaces
    // temp = ft_split(new_args, ' ');
    // free(new_args);
    // if (check_digit(temp) < 0)
    //     return (1);
    // // convert string ti integer
    // i = 0;
    // while (temp[i])
    //     i++;
    // printf("%d\n", i);
    // i = 0;
    // while(temp[i])
    //     printf("here:%s\n", temp[i++]);
}