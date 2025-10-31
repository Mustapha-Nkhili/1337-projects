/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-khili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 17:14:40 by mn-khili          #+#    #+#             */
/*   Updated: 2025/10/20 09:52:18 by mn-khili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	trimed_str_len;
	size_t	s1_len;
	size_t	start;

	if (!s1 || !set)
		return (NULL);
	s1_len = ft_strlen(s1);
	trimed_str_len = 0;
	start = 0;
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	while (s1_len > start && ft_strchr(set, s1[s1_len - 1]))
		s1_len--;
	trimed_str_len = s1_len - start;
	if (trimed_str_len == 0)
		return (ft_strdup(""));
	return (ft_substr(s1, start, trimed_str_len));
}
