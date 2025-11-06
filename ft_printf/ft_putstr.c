/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-khili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:37:18 by mn-khili          #+#    #+#             */
/*   Updated: 2025/11/04 21:03:57 by mn-khili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *str)
{
	int		write_result;
	int		str_len;

	if (!str)
		str = "(null)";
	str_len = 0;
	while (*str)
	{
		write_result = write(1, str, 1);
		if (write_result == -1)
			return (-1);
		str_len++;
		str++;
	}
	return (str_len);
}
