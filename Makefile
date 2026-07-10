
CFLAGS = -Wall -Werror -Wextra
CC = cc

NAME = push_swap

SRCS =	chunking_sort.c \
		main.c \
		master_sort.c \
		options.c \
		printstack.c \
		push.c \
		radix_sort.c \
		reverse_rotate.c \
		rotate.c \
		selection_sort.c \
		swap.c \
		t_stack.c \
		validate.c
OBJ = $(SRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I . -I $(LIBFT_DIR)

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDES) -L$(LIBFT_DIR) -lft -o $(NAME)

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all