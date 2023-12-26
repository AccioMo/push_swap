CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = push_swap
BONUS_NAME = checker
LIBS = libft.a libftprintf.a
HEADER = push_swap.h
BONUS_HEADER = push_swap_bonus.h
SRC = push_swap_main.c push_swap_input.c push_swap_tools.c push_swap_utils.c push_swap_struct.c push_swap_rotations.c push_swap_targets.c push_swap_a.c push_swap_b.c
BONUS_SRC = checker_main_bonus.c checker_tools_bonus.c checker_utils2_bonus.c checker_utils_bonus.c checker_input_bonus.c

all: $(NAME)

$(NAME): $(LIBS) $(SRC) $(HEADER)
	$(CC) $(FLAGS) $(SRC) $(LIBS) -o $(NAME) -g

bonus: $(LIBS) $(BONUS_SRC) $(BONUS_HEADER)
	$(CC) $(FLAGS) $(BONUS_SRC) -o $(BONUS_NAME) $(LIBS)

%.a: %/ %/Makefile
	make -C $< re && make -C $< clean && mv -v $<$@ $@

clean:
	rm -f $(LIBS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus