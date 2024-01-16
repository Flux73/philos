#include "../philo.h"

void sleeping(unsigned long time_ms)
{
    unsigned long t;

    t = get_time_ms();
    while (get_time_ms() - t - 0 < time_ms);
}