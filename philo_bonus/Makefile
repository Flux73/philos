NAME=philo_bonus
HEADER=philo_bonus.h
CC=cc
CFLAGS=
RM= rm -f

# ROUTINE=routine/ft_die.c routine/ft_eat.c routine/ft_grab.c routine/ft_think.c routine/ft_sleep.c

ERROR=error/error_args.c

PARSING=parsing/parse_input.c

CODE=code/init_fork.c code/init_philos.c

UTILS=utils/get_time_ms.c

SRC=philo_bonus.c lib/ft_atoi.c $(ERROR) $(PARSING) $(CODE) $(UTILS)

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cc $(OBJ) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all