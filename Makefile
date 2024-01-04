CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = push_swap
BONUS_NAME = checker
LIBFT = libft/libft.a
LIBFT_DIR = libft/
HEADER = push_swap.h
BONUS_HEADER = checker_bonus.h
SRC = push_swap_main.c push_swap_input.c push_swap_tools.c push_swap_utils.c push_swap_struct.c push_swap_rotations.c push_swap_targets.c push_swap_a.c push_swap_b.c
SRC_O = $(SRC:.c=.o)
BONUS_SRC = checker_main_bonus.c checker_functions_bonus.c checker_tools_bonus.c checker_utils2_bonus.c checker_utils_bonus.c checker_input_bonus.c
GET_NEXT_LINE = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
BONUS_SRC_O = $(BONUS_SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(SRC_O) $(HEADER)
	$(CC) $(FLAGS) $(SRC_O) $(LIBFT) -o $(NAME)

bonus: $(LIBFT) $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_SRC_O) $(BONUS_HEADER)
	$(CC) $(FLAGS) $(BONUS_SRC_O) $(GET_NEXT_LINE) $(LIBFT) -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT): $(LIBFT_DIR)
	@make -C $(LIBFT_DIR)

clean:
	rm -f $(SRC_O) $(BONUS_SRC_O)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus $(LIBFT)
