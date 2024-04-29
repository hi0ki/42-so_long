FILES= gnl/get_next_line.c gnl/get_next_line_utils.c ft_split.c main.c check_map.c utils.c

NAME=so_long
CC= cc -Werror -Wall -Wextra MLX42/build/libmlx42.a -I"MLX42/include/MLX42/MLX42.h" -lglfw -L"/Users/eel-ansa/.brew/opt/glfw/lib/"
RM= rm -rf

all :$(NAME)

$(NAME): so_long.h gnl/get_next_line.h $(FILES)
	$(CC) $(FILES) -o $(NAME)

fclean:
	$(RM) $(NAME)

re: fclean all