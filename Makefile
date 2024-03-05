NAME = so_long
LIBMLX = libmlx_Linux.a
LIBFT = ./libft/libft.a
SRC = main.c
FLAGSMLX = -Lmlx -lXext -lX11
FLAGS = -Wall -Wextra -Werror

$(NAME):
	cc $(FLAGS) -c ./get_next_line/*.c
	mv *.o ./get_next_line
	$(MAKE) -C ./libft
	cc $(FLAGS) $(SRC) $(LIBMLX) $(FLAGSMLX) $(LIBFT) ./get_next_line/*.o

minilibx:
	wget https://cdn.intra.42.fr/document/document/22065/minilibx-linux.tgz
	tar -xvzf minilibx-linux.tgz
	rm minilibx-linux.tgz
	$(MAKE) -C ./minilibx-linux

clean:
	make clean -C ./libft

fclean: clean
		rm ./libft/libft.a