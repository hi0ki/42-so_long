/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ansa <eel-ansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:54:23 by eel-ansa          #+#    #+#             */
/*   Updated: 2024/05/04 12:50:52 by eel-ansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_ber(char *str)
{
	int		i;
	int		j;
	char	*s;

	s = ".ber";
	i = 0;
	j = 4;
	while (str[i])
		i++;
	while (i >= 0 && j >= 0)
	{
		if (str[i] != s[j])
		{
			puterror("Error: Invalid file extension. Expected '.ber'\n");
			return (-1);
		}
		j--;
		i--;
	}
	return (0);
}

int	check_walls(t_mlx *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s->map[i][len])
	{
		if (s->map[i][len] != '1')
			return (puterror("Error: the map is not surrounded by walls\n"), -1);
		len++;
	}
	while (s->map[i])
	{
		if (s->map[i][0] != '1' || s->map[i][len - 1] != '1')
			return (puterror("Error: the map is not surrounded by walls\n"), -1);
		i++;
	}
	len = 0;
	while (s->map[i - 1][len])
	{
		if (s->map[i - 1][len] != '1')
			return (puterror("Error: the map is not surrounded by walls\n"), -1);
		len++;
	}
	return (0);
}

int	check_coins_e(t_mlx *s)
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
			else if (s->map[i][j] == 'E')
				exit += 1;
			j++;
		}
		i++;
	}
	if (exit > 1 || exit == 0 || coins == 0)
		return (puterror("Error: coins or exit\n"), 0);
	return (coins);
}

int	check_player(t_mlx *s)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (s->map[i])
	{
		j = 0;
		while (s->map[i][j])
		{
			if (s->map[i][j] == 'P')
				count += 1;
			else if (s->map[i][j] != '1' && s->map[i][j] != 'P' &&
			s->map[i][j] != 'C' && s->map[i][j] != 'E' &&
				s->map[i][j] != '0' && s->map[i][j] != 'R')
				return (puterror("Error: Invalid character in map\n"), -1);
			j++;
		}
		i++;
	}
	if (count == 1)
		return (0);
	return (puterror("Error: Map must contain exactly one player"), -1);
}

void	check_path(char **map, int x, int y, t_mlx *s)
{
	if (map[y][x] == '1' || (y <= 0 || y >= arrlen(s)) ||
	(x <= 0 || x >= ft_strlen(map[0])))
		return ;
	else if (map[y][x] == 'C')
		s->coins += 1;
	else if (map[y][x] == 'E')
		s->exit += 1;
	if (map[y][x] != '1')
		map[y][x] = '1';
	check_path(map, x + 1, y, s);
	check_path(map, x - 1, y, s);
	check_path(map, x, y + 1, s);
	check_path(map, x, y - 1, s);
}
