NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c for_error.c for_path.c

OBJS = $(SRC:.c=.o)

LIB = libft/libft.a

all: $(LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

$(LIB):
	make -C libft

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
