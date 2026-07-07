
CFLAGS = -Wall -Werror -Wextra
CC = cc

NAME = pushswap.a

SRCS =	main.c \
		printstack.c \
		push.c \
		reverse_rotate.c \
		rotate.c \
		swap.c \
		t_stack.c \
		validate.c
OBJ = $(SRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all