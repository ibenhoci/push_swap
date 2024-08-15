NAME = push_swap

SOURCE = ./src/main.c \
			./src/parsing.c \
			./src/utils.c \
			./src/utils2.c \
			./src/sorting.c \
			./src/utils3.c \
			./src/utils4.c \
			./src/utils5.c \
			./src/utils6.c \

OBJECTS = $(SOURCE:.c=.o)
FLAGS = -Wall -Wextra -Werror -g
LIBFT = libft/libft.a

$(NAME): $(OBJECTS)
	cd libft && make
	cc $(FLAGS) $(SOURCE) $(LIBFT) -o $(NAME)
all: $(NAME)

clean:
	cd libft && make clean
	rm -f $(OBJECTS)

fclean: clean
		cd libft && make fclean
		rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re
