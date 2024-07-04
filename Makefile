SRC = main.c display.c instructions.c stack.c parser.c push_swap.c push_swap.c utils.c
OBJ = $(addprefix src/,$(SRC:.c=.o))
NAME = push_swap
# CFLAGS = -Wall -Werror -Wextra
CC = cc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -lft -L./libft -o $@

%.o: %.c
	make -C libft
	$(CC) $(CFLAGS) -I./Include -c $< -o $@

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all