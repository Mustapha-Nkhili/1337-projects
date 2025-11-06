/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-khili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:10:07 by mn-khili          #+#    #+#             */
/*   Updated: 2025/10/28 21:19:25 by mn-khili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	s_size(char const *s1, char const *s2, size_t *s1_s, size_t *s2_s)
{
	if (s1)
		*s1_s = ft_strlen(s1);
	if (s2)
		*s2_s = ft_strlen(s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s2_size;
	size_t	s1_size;
	size_t	i;
	size_t	j;

	s1_size = 0;
	s2_size = 0;
	s_size(s1, s2, &s1_size, &s2_size);
	str = malloc(s1_size + s2_size + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (i < s1_size)
	{
		str[i] = s1[i];
		i++;
	}
	while (j < s2_size)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
