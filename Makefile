NAME = so_long
LIBMLX = libmlx_Linux.a
SRC = main.c
FLAGSMLX = -Lmlx -lXext -lX11
FLAGS = -Wall -Wextra -Werror

$(NAME):
	cc $(FLAGS) -c ./get_next_line/*.c
	mv *.o ./get_next_line
	cc $(FLAGS) $(SRC) $(LIBMLX) $(FLAGSMLX) ./get_next_line/*.o
