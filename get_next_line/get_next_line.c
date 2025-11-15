/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-khili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:49:35 by mn-khili          #+#    #+#             */
/*   Updated: 2025/11/13 10:23:17 by mn-khili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*handle_error(char **buffer)
{
	free(*buffer);
	*buffer = NULL;
	return (NULL);
}

char	*get_line(char *buffer)
{
	int		line_len;
	char	*line;
	int		i;

	if (!buffer || buffer[0] == '\0')
		return (NULL);
	line_len = 0;
	while (buffer[line_len] && buffer[line_len] != '\n')
		line_len++;
	if (buffer[line_len] == '\n')
		line_len++;
	line = malloc(line_len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < line_len)
	{
		line[i] = buffer[i];
		i++;
	}
	line[line_len] = '\0';
	return (line);
}

char	*read_until_newline(int fd, char **buffer, char *temp_str)
{
	int	temp_str_len;

	while (!ft_strchr_gnl(*buffer, '\n'))
	{
		temp_str_len = read(fd, temp_str, BUFFER_SIZE);
		if (temp_str_len == -1)
			return (handle_error(buffer));
		temp_str[temp_str_len] = '\0';
		if (temp_str_len == 0)
			return (*buffer);
		*buffer = ft_strjoin_gnl(*buffer, temp_str);
		if (!(*buffer))
			return (NULL);
	}
	return (*buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*temp_str;
	char		*line;
	char		*read_result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp_str = malloc(BUFFER_SIZE + 1);
	if (!temp_str)
		return (handle_error(&buffer));
	read_result = read_until_newline(fd, &buffer, temp_str);
	if (read_result == NULL)
	{
		free(temp_str);
		return (NULL);
	}
	line = get_line(buffer);
	if (!line)
	{
		free(temp_str);
		return (handle_error(&buffer));
	}
	buffer = handle_next_line(buffer);
	free(temp_str);
	return (line);
}
