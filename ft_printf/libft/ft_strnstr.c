/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-khili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:06:26 by mn-khili          #+#    #+#             */
/*   Updated: 2025/10/27 20:56:13 by mn-khili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	d;
	size_t	little_len;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	little_len = 0;
	while (little[little_len])
		little_len++;
	while (big[i] && i < len)
	{
		d = 0;
		while (little[d] && big[i + d] && i + d < len)
		{
			if (little[d] != big[i + d])
				break ;
			d++;
		}
		if (little_len == d)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
