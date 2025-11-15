/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-khili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:11:59 by mn-khili          #+#    #+#             */
/*   Updated: 2025/11/12 11:25:44 by mn-khili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*handle_error(char **buffer)
{
	free(*buffer);
	*buffer = NULL;
	return (NULL);
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

char	*get_line(char *buffer)
{
	char	*line;
	int		i;
	int		line_len;

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
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*temp_str;
	char		*line;
	char		*read_result;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	temp_str = malloc(BUFFER_SIZE + 1);
	if (!temp_str)
		return (handle_error(&(buffer[fd])));
	read_result = read_until_newline(fd, &(buffer[fd]), temp_str);
	if (read_result == NULL)
		return (free(temp_str), NULL);
	line = get_line(buffer[fd]);
	if (!line)
	{
		free(temp_str);
		return (handle_error(&(buffer[fd])));
	}
	buffer[fd] = handle_next_line(buffer[fd]);
	free(temp_str);
	return (line);
}
