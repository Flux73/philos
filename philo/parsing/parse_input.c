#include "../philo.h"

int parse_input(int argc, char **av)
{
    int i;

    i = 0;
    while (++i < argc)
    {
        if (ft_atoi(av[i]) < 1)
        {
            printf("Error: Invalid input!\n");
            printf("Input must be in range of 1 and\
                Max_INT for each argument :)\n");
            return (1);
        }
    }
    return (0);
}