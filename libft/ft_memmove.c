/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-khili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:19:30 by mn-khili          #+#    #+#             */
/*   Updated: 2025/10/27 13:56:42 by mn-khili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*source;
	unsigned char		*destination;

	source = (const unsigned char *)src;
	destination = (unsigned char *)dest;
	if (source < destination && source + n > destination)
	{
		destination += n - 1;
		source += n - 1;
		while (n > 0)
		{
			*destination-- = *source--;
			n--;
		}
	}
	else
	{
		while (n > 0)
		{
			*destination++ = *source++;
			n--;
		}
	}
	return (dest);
}
