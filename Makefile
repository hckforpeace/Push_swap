SRC = main.c display.c instructions.c stack.c parser.c push_swap.c utils.c push.c final_push.c
OBJ = $(SRC:.c=.o)
NAME = push_swap
# CFLAGS = -Wall -Werror -Wextra
CC = cc

all: $(NAME)

$(NAME): $(addprefix src/,$(OBJ))
	$(CC) $(CFLAGS) $^ -lft -L./libft -o $@
	mv $^ obj
%.o: %.c
	make -C libft
	$(CC) $(CFLAGS) -I./Include -c $< -o $@

clean:
	make clean -C libft
	rm -f $(addprefix obj/,$(OBJ))

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all