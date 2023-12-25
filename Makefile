CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = push_swap
LIBS = libft.a libftprintf.a
HEADER = push_swap.h
SRC = main.c push_swap_input.c push_swap_tools.c push_swap_utils.c push_swap_struct.c push_swap_rotations.c push_swap_targets.c push_swap_a.c push_swap_b.c

all: $(NAME)

$(NAME): $(LIBS) $(SRC) $(HEADER)
	$(CC) $(FLAGS) $(SRC) $(LIBS) -o $(NAME) -g

# bonus: $(BONUS_SRC)
# 	$(CC) $(FLAGS) $(BONUS_SRC) -o $(BONUS_NAME) $(LIBFT)

%.a: %/ %/Makefile
	make -C $< re && make -C $< clean && mv -v $<$@ $@

clean:
	rm -f $(LIBS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus