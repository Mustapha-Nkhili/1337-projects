/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-khili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:46:36 by mn-khili          #+#    #+#             */
/*   Updated: 2025/11/04 21:03:43 by mn-khili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	char	*str_nbr;
	int		nbr_len;

	str_nbr = ft_itoa(n);
	if (!str_nbr)
		return (-1);
	nbr_len = ft_putstr(str_nbr);
	free(str_nbr);
	return (nbr_len);
}
