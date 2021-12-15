FLAGS	=	-Wall -Wextra -Werror
NAME	=	mini_paint
CC		=	gcc
SRC		=	mini_paint.c \
			main.c
OBJ		=	$(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC) -o $@

clean:
	rm -fr $(OBJ)

fclean:
	make clean
	rm -fr $(NAME)

re: fclean all
