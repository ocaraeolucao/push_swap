
CFLAGS = -Wall -Werror -Wextra
CC = cc

NAME = pushswap.a

SRCS =	main.c \
		t_stack.c
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