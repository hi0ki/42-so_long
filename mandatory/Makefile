FILES= ../gnl/get_next_line.c ../gnl/get_next_line_utils.c ft_split.c check_map.c utils.c config_map.c mlx_start.c main.c keys.c mlx_walls.c

OBJ= $(FILES:.c=.o)
NAME= ../so_long
CC= cc -Werror -Wall -Wextra
MLX= ../MLX42/build/libmlx42.a -I"../MLX42/include/MLX42/MLX42.h" -lglfw -L"/Users/eel-ansa/.brew/opt/glfw/lib/"
RM= rm -rf

.SILENT:

all :$(NAME)

$(NAME): so_long.h ../gnl/get_next_line.h $(OBJ)
	$(CC) $(OBJ) $(MLX) -o $(NAME)

clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)

re: fclean all