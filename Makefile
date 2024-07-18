SRC = main.c display.c instructions.c stack.c parser.c push_swap.c utils.c push.c final_push.c utils2.c
SRC_BONUS = main_bonus.c display.c instructions.c stack.c parser.c utils.c utils2.c
OBJ = $(addprefix src/,$(SRC:.c=.o))
OBJ_BONUS = $(addprefix src/,$(SRC_BONUS:.c=.o))
NAME = push_swap
NAMEB= checker
CFLAGS = -Wall -Werror -Wextra
CC = cc

all: $(NAME)

bonus: $(NAMEB)

$(NAMEB): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $^ -lft -L./libft -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -lft -L./libft -o $@

%.o: %.c
	make -C libft
	$(CC) $(CFLAGS) -I./Include -c $< -o $@

clean:
	make clean -C libft
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	make fclean -C libft
	rm -f $(NAME) $(NAMEB)

re: fclean all
