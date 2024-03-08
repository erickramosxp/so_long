NAME = so_long
LIBMLX = ./minilibx-linux/libmlx_Linux.a
LIBFT = ./libft/libft.a
SRC1 =	animation_game.c end_game.c get_map.c get_positions.c \
		load_img_map.c load_img_player_in_door.c load_img_player.c get_img_move.c \
		load_img.c move_player.c put_game.c utils_game.c load_enemy.c\
		valid_map.c valid_name_file.c validate_path.c valid_quant_in_map.c
SRC_OBJ = $(SRC1:.c=.o)
SRC = main.c
FLAGSMLX = -Lmlx -lXext -lX11
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	cc $(FLAGS) -c $(addprefix ./src/, $(SRC1))
	mv $(SRC_OBJ) ./src
	$(MAKE) -C ./libft
	cc $(FLAGS) $(SRC) $(addprefix ./src/, $(SRC_OBJ)) $(LIBMLX) $(FLAGSMLX) $(LIBFT) -o $(NAME)

minilibx:
	wget https://cdn.intra.42.fr/document/document/22065/minilibx-linux.tgz
	tar -xvzf minilibx-linux.tgz
	rm minilibx-linux.tgz
	$(MAKE) -C ./minilibx-linux

clean:
	make clean -C ./libft
	@ rm -f $(addprefix ./src/, $(SRC_OBJ))

fclean: clean
	rm -f ./libft/ft_printf/libftprintf.a
	rm -f ./libft/libft.a
	rm -f so_long

re: fclean $(NAME)
