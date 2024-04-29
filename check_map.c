/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ansa <eel-ansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:54:23 by eel-ansa          #+#    #+#             */
/*   Updated: 2024/04/29 14:36:09 by eel-ansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	check walls : ✔️
	check coins	: ✔️
	check path
	check player : ✔️
	check exit : ✔️
*/

char	**copy_arr(mlx *s)
{
	int		i;
	int		x;
	char	**arr;

	i = 0;
	x = arrlen(s);
	arr = malloc(x * sizeof(char *));
	while (s->map[i])
	{
		arr[i] = ft_strdup(s->map[i]);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

int	check_walls(mlx *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s->map[i][len])
	{
		if (s->map[i][len] != '1')
			return (-1);
		len++;
	}
	while (s->map[i])
	{
		if (s->map[i][0] != '1' || s->map[i][len - 1] != '1')
			return (-1);
		i++;
	}
	len = 0;
	while (s->map[i - 1][len])
	{
		if (s->map[i - 1][len] != '1')
			return (-1);
		len++;
	}
	return (0);
}

int	check_coins_e(mlx *s)
{
	int	i;
	int	j;
	int	coins;
	int	exit;

	i = 0;
	coins = 0;
	exit = 0;
	while (s->map[i])
	{
		j = 0;
		while (s->map[i][j])
		{
			if (s->map[i][j] == 'C')
				coins += 1;
			if (s->map[i][j] == 'E')
				exit += 1; 
			j++;
		}
		i++;
	}
	if (exit > 1 || exit == 0)
		return (0);
	return (coins);
}

int	check_player(mlx *s)
{
	int	i;
	int	j;

	i = 0;
	while (s->map[i])
	{
		j = 0;
		while (s->map[i][j])
		{
			if (s->map[i][j] == 'P')
				return (0);
			j++;
		}
		i++;
	}
	return (-1);
}

void	check_path(char **map, int x, int y, mlx *s)
{
	if (map[x][y] == '1' || (x <= 0 || x >= arrlen(s))
	|| (y <= 0 || y >= ft_strlen(map[0])))
		return ;
	else if (map[x][y] == 'C')
		s->coins += 1;
	else if (map[x][y] == 'E')
		s->exit += 1;
	if (map[x][y] != '1')
		map[x][y] = '1';
	check_path(map, x + 1, y, s);
	check_path(map, x - 1, y, s);
	check_path(map, x, y + 1, s);
	check_path(map, x, y - 1, s);
}
