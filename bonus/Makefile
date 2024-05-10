FILES= ../gnl/get_next_line.c ../gnl/get_next_line_utils.c ft_split_bonus.c check_map_bonus.c utils_bonus.c config_map_bonus.c mlx_start_bonus.c main_bonus.c keys_bonus.c mlx_walls_bonus.c bonus_coin.c itoa_bonus.c

OBJ= $(FILES:.c=.o)
NAME= ../so_long_bonus
CC= cc -Werror -Wall -Wextra
MLX= ../MLX42/build/libmlx42.a -I"../MLX42/include/MLX42/MLX42.h" -lglfw -L"/Users/eel-ansa/.brew/opt/glfw/lib/"
RM= rm -rf

.SILENT:

all :$(NAME)

$(NAME): so_long_bonus.h ../gnl/get_next_line.h $(OBJ)
	$(CC) $(OBJ) $(MLX) -o $(NAME)

clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)

re: fclean all