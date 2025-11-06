/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-khili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 10:00:00 by mn-khili          #+#    #+#             */
/*   Updated: 2025/11/04 21:03:17 by mn-khili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	fill_rest_array(char *rest_array, size_t n, int hex_form)
{
	char	*hex;
	int		len;

	hex = "0123456789abcdef";
	if (hex_form)
		hex = "0123456789ABCDEF";
	len = 0;
	while (n > 0)
	{
		rest_array[len] = hex[n % 16];
		len++;
		n /= 16;
	}
	return (len);
}

int	ft_puthex(size_t n, int is_upper_format)
{
	int		len;
	int		write_result;
	char	rest_array[42];
	int		i;

	if (n == 0)
	{
		write_result = write(1, "0", 1);
		if (write_result == -1)
			return (-1);
		return (1);
	}
	len = fill_rest_array(rest_array, n, is_upper_format);
	i = len;
	while (i > 0)
	{
		write_result = write(1, &rest_array[i - 1], 1);
		if (write_result == -1)
			return (-1);
		i--;
	}
	return (len);
}
