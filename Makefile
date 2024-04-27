FILES= gnl/get_next_line.c gnl/get_next_line_utils.c ft_split.c main.c check_map.c

NAME=so_long
CC= cc -Werror -Wall -Wextra

all :$(NAME)

$(NAME): so_long.h gnl/get_next_line.h $(FILES)
	$(CC) $(FILES) -o $(NAME)
