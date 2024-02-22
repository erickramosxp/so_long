NAME = so_long
LIBMLX = libmlx_Linux.a
SRC = main.c
FLAGSMLX = -Lmlx -lXext -lX11
FLAGS = -Wall -Wextra -Werror

$(NAME):
	cc $(FLAGS) $(SRC) $(LIBMLX) $(FLAGSMLX)
