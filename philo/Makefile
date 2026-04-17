CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =	src/main.c \
		src/error/error_handler.c \
		src/free/free.c \
		src/parsing/parsing.c \
		src/utils/utils.c \
		src/exec/routine.c \
		src/exec/actions.c \
		src/exec/monitor.c \
		src/exec/routine_utils.c \
		src/parsing/init/init_forks.c \
		src/parsing/init/init_monitor.c \
		src/parsing/init/init_philosophers.c 


OBJS = $(SRCS:.c=.o)

INCLUDES = -I include

NAME = philo

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(SRCS) -I. -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all re fclean clean