/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ansa <eel-ansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:59:43 by eel-ansa          #+#    #+#             */
/*   Updated: 2024/05/02 22:49:03 by eel-ansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void mini_putnbr(int nbr)
{
	char c;
	if (nbr > 9)
		mini_putnbr(nbr / 10);
	c = nbr % 10 + '0';
	write(1, &c, 1);
	write(1, "\n", 1);
}
int	arrlen(mlx *s)
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
