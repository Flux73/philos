#include "../philo.h"

unsigned long get_time_ms(void)
{
    struct timeval curr_time;

    gettimeofday(&curr_time, 0);
    return (curr_time.tv_sec * 1000 + curr_time.tv_usec / 1000); 
}