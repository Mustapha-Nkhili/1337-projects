/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-khili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:41:57 by mn-khili          #+#    #+#             */
/*   Updated: 2025/11/04 21:04:52 by mn-khili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	nbr_length(unsigned int nbr)
{
	size_t	i;

	if (nbr == 0)
		return (1);
	i = 0;
	while (nbr > 0)
	{
		i++;
		nbr /= 10;
	}
	return (i);
}

static void	fill_str(char *str, size_t len, unsigned int nbr)
{
	str[len] = '\0';
	while (len > 0)
	{
		len--;
		str[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
}

char	*ft_utoa(unsigned int n)
{
	char	*str;
	size_t	nbr_len;

	nbr_len = nbr_length(n);
	str = malloc((sizeof(char) * nbr_len) + 1);
	if (!str)
		return (NULL);
	fill_str(str, nbr_len, n);
	return (str);
}
