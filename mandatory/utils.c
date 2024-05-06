/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ansa <eel-ansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:59:43 by eel-ansa          #+#    #+#             */
/*   Updated: 2024/05/04 12:03:48 by eel-ansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	puterror(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	exit(EXIT_FAILURE);
}

void	mini_putnbr(int nbr)
{
	char	c;

	if (nbr > 9)
		mini_putnbr(nbr / 10);
	c = nbr % 10 + '0';
	write(1, &c, 1);
}

int	arrlen(t_mlx *s)
{
	int	i;

	i = 0;
	while (s->map[i])
		i++;
	return (i);
}

void	arrfree(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**copy_arr(t_mlx *s)
{
	int		i;
	int		x;
	char	**arr;

	i = 0;
	x = arrlen(s);
	arr = malloc((x + 1) * sizeof(char *));
	while (s->map[i])
	{
		arr[i] = ft_strdup(s->map[i]);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
