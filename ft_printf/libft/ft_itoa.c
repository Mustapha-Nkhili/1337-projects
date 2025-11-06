/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-khili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 11:45:04 by mn-khili          #+#    #+#             */
/*   Updated: 2025/10/21 18:53:41 by mn-khili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nbr_length(long nbr)
{
	size_t	i;

	i = 0;
	while (nbr > 0)
	{
		i++;
		nbr /= 10;
	}
	return (i);
}

static void	fill_str(char *str, size_t len, long nbr, int is_negative)
{
	size_t	i;

	i = len;
	if (is_negative)
		str[0] = '-';
	while (i > 0 && nbr > 0)
	{
		str[i - 1] = (nbr % 10) + 48;
		nbr /= 10;
		i--;
	}
	str[len] = '\0';
}

static char	*handle_0_input(void)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	nbr_len;
	int		is_negative;
	long	nbr;

	nbr = (long)n;
	nbr_len = 0;
	is_negative = 0;
	if (nbr < 0)
	{
		nbr_len = 1;
		is_negative = 1;
		nbr = -nbr;
	}
	if (nbr == 0)
		return (handle_0_input());
	nbr_len += nbr_length(nbr);
	str = malloc((sizeof(char) * nbr_len) + 1);
	if (!str)
		return (NULL);
	fill_str(str, nbr_len, nbr, is_negative);
	return (str);
}
