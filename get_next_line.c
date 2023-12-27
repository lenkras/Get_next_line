/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epolkhov <epolkhov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:46:12 by epolkhov          #+#    #+#             */
/*   Updated: 2023/12/21 18:39:45 by epolkhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*buffer = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (ft_free(&buffer));
	buffer = read_from_file(fd, buffer);
	if (!buffer)
		return (ft_free(&buffer));
	line = find_line(buffer);
	buffer = getrest_of_file(buffer);
	if (!line || !buffer)
	{
		free (buffer);
		buffer = NULL;
	}
	return (line);
}

char	*read_from_file(int fd, char *buffer)
{
	char	*tmp;
	int		bytes;

	buffer = check_string(buffer);
	if (!buffer)
		return (0);
	tmp = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (ft_free(&buffer));
	bytes = 1;
	while (!ft_strchr(buffer, '\n') && bytes != 0)
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes == -1)
			return (ft_free(&tmp));
		tmp[bytes] = '\0';
		buffer = ft_strjoin(buffer, tmp);
		if (!buffer)
			return (ft_free(&buffer));
	}
	free (tmp);
	return (buffer);
}

char	*find_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		line = (char *)malloc(sizeof(char) * (i + 2));
	else
		line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*getrest_of_file(char *buffer)
{
	int		i;
	int		j;
	char	*reminder;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free (buffer);
		return (NULL);
	}
	reminder = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!reminder)
		return (ft_free(&buffer));
	i++;
	j = 0;
	while (buffer[i])
		reminder[j++] = buffer[i++];
	reminder[j] = '\0';
	free (buffer);
	return (reminder);
}
