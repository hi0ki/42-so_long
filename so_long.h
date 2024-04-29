/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ansa <eel-ansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:29:35 by eel-ansa          #+#    #+#             */
/*   Updated: 2024/04/29 14:30:29 by eel-ansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H


#include "MLX42/include/MLX42/MLX42.h"
#include "gnl/get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct mlx_struct{
	char **map;
	int	x;
	int	y;
	int coins;
	int exit;
} mlx;

/*				check map				*/
int		check_walls(mlx *s);
int		check_coins_e(mlx *s);
int		check_player(mlx *s);
void	check_path(char **map, int x, int y, mlx *s);

/*				  utils				*/
char	**ft_free(char **str, int i);
char	**ft_split(char const *s, char c);
int arrlen(mlx *s);
void	arrfree(char **arr);
char **copy_arr(mlx *s);

#endif