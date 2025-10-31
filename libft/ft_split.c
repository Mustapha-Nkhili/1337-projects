/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-khili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 09:54:09 by mn-khili          #+#    #+#             */
/*   Updated: 2025/10/21 11:07:38 by mn-khili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	words_count(char const *s, char c)
{
	int	i;
	int	words_nbr;
	int	is_new_word;

	i = 0;
	is_new_word = 0;
	words_nbr = 0;
	while (s[i])
	{
		if (s[i] != c && !is_new_word)
		{
			words_nbr++;
			is_new_word = 1;
		}
		if (is_new_word && s[i] == c)
			is_new_word = 0;
		i++;
	}
	return (words_nbr);
}

static void	fill_str(char *str, char const *original_str, size_t len, int start)
{
	size_t	i;

	i = 0;
	while (i < len)
		str[i++] = original_str[start++];
	str[i] = '\0';
}

static char	*get_word(char const *s, char c, size_t *start)
{
	size_t	word_len;
	size_t	word_start_index;
	char	*str;

	word_len = 0;
	word_start_index = *start;
	while (s[*start] && s[*start] != c)
	{
		*start += 1;
		word_len++;
	}
	str = malloc(sizeof(char) * word_len + 1);
	if (!str)
		return (NULL);
	fill_str(str, s, word_len, word_start_index);
	while (s[*start] == c && s[*start])
		*start += 1;
	return (str);
}

static char	**free_split(char **splited_str, size_t i)
{
	while (i > 0)
		free(splited_str[--i]);
	free(splited_str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	start;
	size_t	words_nbr;
	char	**splited_str;
	size_t	i;

	if (!s)
		return (NULL);
	words_nbr = words_count(s, c);
	splited_str = malloc((words_nbr + 1) * sizeof(char *));
	if (!splited_str)
		return (NULL);
	start = 0;
	while (s[start] == c && s[start])
		start++;
	i = 0;
	while (i < words_nbr)
	{
		splited_str[i] = get_word(s, c, &start);
		if (!splited_str[i])
			return (free_split(splited_str, i));
		i++;
	}
	splited_str[i] = NULL;
	return (splited_str);
}
