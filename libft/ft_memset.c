/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-khili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:43:44 by mn-khili          #+#    #+#             */
/*   Updated: 2025/10/26 14:37:11 by mn-khili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*data;
	unsigned char	remplacement;

	data = (unsigned char *)s;
	remplacement = (unsigned char)c;
	while (n > 0)
	{
		*data = remplacement;
		data++;
		n--;
	}
	return (s);
}
