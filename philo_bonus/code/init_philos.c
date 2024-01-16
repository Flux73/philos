#include "../philo_bonus.h"

static int args_len(char **av)
{
    int i;

    i = 0;
    while (av[i])
        i++;
    return (i);
}

static void check_optional_arg(t_data *arr, char **av)
{
    if (args_len(av) == 5)
        arr->num_of_meals = ft_atoi(av[4]);
    else
        arr->num_of_meals = -1;
}

static void *rout(void *data)
{
    t_data *d = (t_data *)data;

    while (1)
    {
        if (d->num_of_meals != 0 && get_time_ms() - d->starting - d->last_meal_time >= d->time_to_die)
        {
            sem_wait(d->print_sem);
            printf("%lu %d died\n", get_time_ms() - d->starting, d->philo_id);
            kill(0, SIGKILL);
        }
    }
    return (NULL);
}

static void routine(t_data *data, t_data *arr_to_free)
{
    pthread_t t;

    pthread_create(&t, 0, &rout, data);
    pthread_detach(t);
    while (1)
    {
        sem_wait(data->print_sem);
        printf("%lu %d is thinking\n", get_time_ms() - data->starting, data->philo_id);
        sem_post(data->print_sem);
        sem_wait(data->forks_sem);
        sem_wait(data->print_sem);
        printf("%lu %d has taken a fork\n", get_time_ms() - data->starting, data->philo_id);
        sem_post(data->print_sem);
        sem_wait(data->print_sem);
        printf("%lu %d is thinking\n", get_time_ms() - data->starting, data->philo_id);
        sem_post(data->print_sem);
        sem_wait(data->forks_sem);
        sem_wait(data->print_sem);
        printf("%lu %d has taken a fork\n", get_time_ms() - data->starting, data->philo_id);
        sem_post(data->print_sem);
        sem_wait(data->print_sem);
        printf("%lu %d is eating\n", get_time_ms() - data->starting, data->philo_id);
        sem_post(data->print_sem);
        data->last_meal_time = get_time_ms() - data->starting;
        (data->num_of_meals)--;
        usleep(data->time_to_eat * 1000);
        sem_post(data->forks_sem);
        sem_post(data->forks_sem);
        if (data->num_of_meals == 0)
        {
            free(arr_to_free);
            sem_close(data->forks_sem);
            sem_close(data->print_sem);
            exit(0);
        }
        sem_wait(data->print_sem);
        printf("%lu %d is sleeping\n", get_time_ms() - data->starting, data->philo_id);
        sem_post(data->print_sem);
        usleep(data->time_to_sleep * 1000);
    }
}

t_data *init_philos(char **av, sem_t *forks_sem, sem_t *print_sem)
{
    int i;
    pid_t pid;
    t_data *arr;
    unsigned long start;

    arr = (t_data *)malloc(sizeof(t_data) * ft_atoi(av[0]));
    if (!arr)
        return (NULL);
    i = -1;
    start = get_time_ms();
    while (++i < ft_atoi(av[0]))
    {
        pid = fork();
        arr[i].philo_id = i + 1;
        arr[i].philo = pid;
        arr[i].starting = start;
        arr[i].last_meal_time = get_time_ms() - arr[i].starting;
        check_optional_arg(&arr[i], av);
        arr[i].time_to_die = ft_atoi(av[1]);
        arr[i].time_to_eat = ft_atoi(av[2]);
        arr[i].time_to_sleep = ft_atoi(av[3]);
        arr[i].print_sem = print_sem;
        arr[i].forks_sem = forks_sem;
        if (pid == 0)
            routine(&arr[i], arr);
    }
    return (arr);
}