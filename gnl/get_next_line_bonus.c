/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ansa <eel-ansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:38:20 by eel-ansa          #+#    #+#             */
/*   Updated: 2024/01/23 22:02:25 by eel-ansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(int fd, char *save)
{
	char	*buffer;
	int		byte;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	byte = 1;
	while (byte != 0 && chr_n(save) == -1)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == -1)
		{
			free(buffer); 
			buffer = NULL;
			free(save);
			save = NULL;
			return (buffer);
		}
		buffer[byte] = '\0';
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	buffer = NULL;
	return (save);
}

char	*ft_line(char *save)
{
	char	*line;
	int		i;
	int		index;

	if (ft_strlen(save) == 0)
		return (NULL);
	index = chr_n(save);
	if (index == -1)
		return (ft_strdup(save));
	line = malloc(index + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (i < index)
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\n';
	line[i + 1] = '\0';
	return (line);
}

char	*ft_save(char *save)
{
	char	*str;
	int		index;

	index = chr_n(save);
	if (index != -1)
	{
		str = ft_strdup(save + index + 1);
		free(save);
		save = NULL;
		return (str);
	}
	free(save);
	save = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	char		*line;

	if (fd > OPEN_MAX || BUFFER_SIZE <= 0 || (fd <= 2 && fd == -1))
		return (NULL);
	save[fd] = ft_read(fd, save[fd]);
	if (!save[fd])
	{
		free(save[fd]);
		save[fd] = NULL;
		return (NULL);
	}
	line = ft_line(save[fd]);
	save[fd] = ft_save(save[fd]);
	return (line);
}
