/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-khili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 13:49:02 by mn-khili          #+#    #+#             */
/*   Updated: 2025/10/16 15:03:01 by mn-khili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*data;
	unsigned char	character;

	data = (unsigned char *)s;
	character = (unsigned char)c;
	while (n--)
	{
		if (*data == character)
			return ((void *)data);
		data++;
	}
	return (NULL);
}
