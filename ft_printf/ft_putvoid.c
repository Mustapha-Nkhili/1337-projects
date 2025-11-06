/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-khili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 14:15:55 by mn-khili          #+#    #+#             */
/*   Updated: 2025/11/04 21:04:37 by mn-khili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putvoid(void *p)
{
	char	*str;
	size_t	n;
	int		str_len;
	int		hex_len;

	if (p == NULL)
	{
		str = "(nil)";
		return (ft_putstr(str));
	}
	n = (size_t)p;
	str_len = ft_putstr("0x");
	if (str_len == -1)
		return (-1);
	hex_len = ft_puthex(n, 0);
	if (hex_len == -1)
		return (-1);
	str_len += hex_len;
	return (str_len);
}
