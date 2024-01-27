NAME=philo
HEADER=philo.h
CC=cc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f

ROUTINE=routine/ft_die.c routine/ft_eat.c routine/ft_grab.c routine/ft_think.c routine/ft_sleep.c

ERROR=error/error_args.c

CODE=code/create_forks.c code/create_philos.c code/check_death.c code/init_threads.c\
	code/create_extra_mutexes.c

UTILS=utils/get_time_ms.c utils/collecting_mutexes.c utils/detaching_threads.c utils/sleeping.c

SRC=philo.c $(UTILS) $(CODE) $(ERROR) parsing/parse_input.c\
	lib/ft_atoi.c $(ROUTINE)
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ -pthread -o $@

%.o:%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re