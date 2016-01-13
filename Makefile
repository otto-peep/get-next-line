NAME = gnl

LIB = -L ./libft -lft

SRC = ./get_next_line.c	./main.c

HEAD = -I ./get_next_line.h

all: $(NAME)

$(NAME):
		gcc -o $(NAME) $(SRC) $(HEAD) $(LIB)

clean:
		rm -f $(NAME)

fclean: clean

re: fclean all
