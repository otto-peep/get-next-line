NAME = gnl

LIB = -L ./libft -lft

SRC = ./newgnl.c	./main.c

HEAD = -I ./ -I ./libft/

all: $(NAME)

$(NAME):
		gcc -o $(NAME) $(SRC) $(HEAD) $(LIB)

clean:
		rm -f $(NAME)

fclean: clean

re: fclean all
