CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = philo

SRC = utils.c ft_atoi.c threads.c

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) main.c $(OBJS) -o philo

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
