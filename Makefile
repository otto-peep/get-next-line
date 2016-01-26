NAME = gnl

LIB = -L ./libft -lft

SRC = ./get_next_line.c	./main.c

HEAD = -I ./ -I ./libft/

all: $(NAME)

$(NAME):
		gcc -Wall -Wextra -Werror -o $(NAME) $(SRC) $(HEAD) $(LIB)

clean:
		rm -f $(NAME)

fclean: clean

re: fclean all
