/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-khili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:25:57 by mn-khili          #+#    #+#             */
/*   Updated: 2025/10/23 09:47:54 by mn-khili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	n_len(long n)
{
	size_t	n_len;

	n_len = 0;
	while (n > 0)
	{
		n_len++;
		n /= 10;
	}
	return (n_len);
}

static void	fill_nbrs_array(char *nbrs, long nbr, int is_negative)
{
	int		i;
	size_t	nbrs_len;

	nbrs_len = n_len(nbr);
	if (is_negative)
		nbrs_len++;
	i = nbrs_len - 1;
	nbrs[nbrs_len] = '\0';
	while (i >= 0 && nbr > 0)
	{
		nbrs[i] = (nbr % 10) + 48;
		nbr /= 10;
		i--;
	}
	if (is_negative)
		nbrs[i] = '-';
}

void	ft_putnbr_fd(int n, int fd)
{
	char	nbrs[13];
	long	nbr;
	int		is_negative;

	is_negative = 0;
	nbr = (long)n;
	if (nbr < 0)
	{
		is_negative = 1;
		nbr = -nbr;
	}
	if (nbr == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	fill_nbrs_array(nbrs, nbr, is_negative);
	write(fd, nbrs, ft_strlen(nbrs));
}
