/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ansa <eel-ansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:29:35 by eel-ansa          #+#    #+#             */
/*   Updated: 2024/05/04 12:05:35 by eel-ansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H


# include "../MLX42/include/MLX42/MLX42.h"
# include "../gnl/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct enemy{
	mlx_t	*mlx;
	void **texture;
	int		x;
	int		y;
	int		i;
	int		j;
}t_emy;

typedef struct mlx_struct{
	char		**map;
	mlx_t		*mlx;
	mlx_image_t	*player;
	void		**texture;
	int			x;
	int			y;
	int			moves;
	int			coins;
	int			exit;
	int			width;
	int			height;
	int			c_x;
	int			c_y;
	int			time;
	int			pic;
}t_mlx;

/*				check map				*/
int		check_walls(t_mlx *s);
int		check_coins_e(t_mlx *s);
int		check_player(t_mlx *s);
void	check_path(char **map, int x, int y, t_mlx *s);
int		config_map(t_mlx *s, int fd);
int		check_ber(char *str);
/*				MLX utils             */
void	put_walls(t_mlx *s, int x, int y);
void	put_ground(t_mlx *s, int x, int y);
void	my_keys(mlx_key_data_t keydata, void *param);
void	get_walls_ground(t_mlx *s, mlx_t *mlx);
void	take_thecoins(t_mlx *s, int x, int y, char *str);
void	my_keys(mlx_key_data_t keydata, void *param);
void	get_player(t_mlx *s, char *str, int x, int y);
/*				  utils				*/
char	**ft_free(char **str, int i);
char	**ft_split(char const *s, char c);
int		arrlen(t_mlx *s);
void	arrfree(char **arr);
char	**copy_arr(t_mlx *s);
void	find_player(t_mlx *s);
void	mini_putnbr(int nbr);
void	puterror(char *str);
/*				bonus           */
void 	get_coins(t_mlx *s);
void  start_loop(void *param);
void	get_exit(t_mlx *s);
void	get_enemy(t_mlx *s, t_emy *str);
void	delete_tex(void **texture);

#endif