/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-khili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:47:18 by mn-khili          #+#    #+#             */
/*   Updated: 2025/11/11 13:07:19 by mn-khili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr_gnl(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str && *str != c)
	{
		str++;
	}
	if (*str == c)
		return ((char *)str);
	return (NULL);
}

static void	s_size(char *buffer, char *s2, size_t *buffer_s, size_t *s2_s)
{
	int	i;

	i = 0;
	if (buffer)
	{
		while (buffer[i])
			i++;
		*buffer_s = i;
	}
	if (s2)
	{
		i = 0;
		while (s2[i])
			i++;
		*s2_s = i;
	}
}

char	*ft_strjoin_gnl(char *buffer, char *s2)
{
	char	*str;
	size_t	s2_size;
	size_t	buffer_size;
	size_t	i;
	size_t	j;

	buffer_size = 0;
	s2_size = 0;
	s_size(buffer, s2, &buffer_size, &s2_size);
	str = malloc(buffer_size + s2_size + 1);
	if (!str)
		return (free(buffer), NULL);
	i = 0;
	j = 0;
	while (i < buffer_size)
	{
		str[i] = buffer[i];
		i++;
	}
	while (j < s2_size)
		str[i++] = s2[j++];
	str[i] = '\0';
	free(buffer);
	return (str);
}

static void	fill_next_line(char *next_line, char *str, int start)
{
	int	i;

	i = 0;
	while (str[start + i])
	{
		next_line[i] = str[start + i];
		i++;
	}
	next_line[i] = '\0';
}

char	*handle_next_line(char *str)
{
	char	*next_line;
	int		start;
	int		str_len;

	if (!str)
		return (NULL);
	start = 0;
	while (str[start] != '\n' && str[start])
		start++;
	if (str[start] == '\0')
		return (free(str), NULL);
	start++;
	str_len = start;
	while (str[str_len])
		str_len++;
	str_len = str_len - start;
	next_line = malloc(str_len + 1);
	if (!next_line)
		return (free(str), NULL);
	fill_next_line(next_line, str, start);
	free(str);
	return (next_line);
}
