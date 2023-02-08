/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:04:53 by nnemeth           #+#    #+#             */
/*   Updated: 2023/01/25 14:05:27 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

char	*read_line(int fd, char *save)
{
	char		*buff;
	int			read_line;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_line = 1;
	while (!ft_strchr(save, '\n') && read_line != 0)
	{
		read_line = read(fd, buff, BUFFER_SIZE);
		if (read_line == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_line] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

char	*get_line(char *save)
{
	char	*temp;
	int		i;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	temp = (char *)malloc(sizeof(char) * (i + 2));
	if (!temp)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		temp[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		temp[i] = save[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*next_line(char *save)
{
	int		i;
	int		y;
	char	*tmp;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 2));
	if (!tmp)
		return (NULL);
	i++;
	y = 0;
	while (save[i])
		tmp[y++] = save[i++];
	tmp[y] = '\0';
	free(save);
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = read_line(fd, save);
	if (!save)
		return (NULL);
	line = get_line(save);
	save = next_line(save);
	return (line);
}
