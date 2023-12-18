CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = push_swap
LIBS = libft.a libftprintf.a
HEADER = push_swap.h
SRC = main.c push_swap.c push_swap_utils.c push_swap_struct.c

all: $(NAME)

$(NAME): $(LIBFT) $(SRC) $(HEADER)
	$(CC) $(FLAGS) $(SRC) $(LIBS) -o $(NAME)

# bonus: $(BONUS_SRC)
# 	$(CC) $(FLAGS) $(BONUS_SRC) -o $(BONUS_NAME) $(LIBFT)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus