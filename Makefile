NAME = so_long
LIBMLX = libmlx_Linux.a
LIBFT = ./libft/libft.a
SRC1 =	animation_game.c end_game.c get_map.c get_positions.c \
		load_img_map.c load_img_player_in_door.c load_img_player.c \
		load_img.c move_player.c put_game.c utils_game.c \
		valid_map.c valid_name_file.c validate_path.c valid_quant_in_map.c
SRC_OBJ = $(SRC1:.c=.o)
SRC_GNL = get_next_line.c get_next_line_utils.c
SRC = main.c
FLAGSMLX = -Lmlx -lXext -lX11
FLAGS = -Wall -Wextra -Werror

$(NAME):
	cc $(FLAGS) -c $(addprefix get_next_line/, $(SRC_GNL))
	mv $(SRC_GNL:.c=.o) ./get_next_line
	cc $(FLAGS) -c $(addprefix ./src/, $(SRC1))
	mv $(SRC_OBJ) ./src
	$(MAKE) -C ./libft
	cc $(FLAGS) $(SRC) $(addprefix ./src/, $(SRC_OBJ)) $(LIBMLX) $(FLAGSMLX) $(LIBFT) $(addprefix get_next_line/, $(SRC_GNL:.c=.o)) -o $(NAME)

minilibx:
	wget https://cdn.intra.42.fr/document/document/22065/minilibx-linux.tgz
	tar -xvzf minilibx-linux.tgz
	rm minilibx-linux.tgz
	$(MAKE) -C ./minilibx-linux

clean:
	make clean -C ./libft

fclean: clean
		rm ./libft/libft.a