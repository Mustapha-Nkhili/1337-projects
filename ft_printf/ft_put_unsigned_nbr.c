/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-khili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:51:18 by mn-khili          #+#    #+#             */
/*   Updated: 2025/11/04 21:04:16 by mn-khili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unsigned_nbr(unsigned int nbr)
{
	char	*str_nbr;
	int		str_len;	

	str_nbr = ft_utoa(nbr);
	if (!str_nbr)
		return (-1);
	str_len = ft_putstr(str_nbr);
	free(str_nbr);
	return (str_len);
}
