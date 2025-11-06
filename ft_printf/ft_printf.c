/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-khili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 14:16:35 by mn-khili          #+#    #+#             */
/*   Updated: 2025/11/04 21:02:54 by mn-khili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format_str(const char *format_str, va_list args)
{
	int	str_len;
	int	result;

	str_len = 0;
	while (*format_str)
	{
		if (*format_str == '%')
		{
			++format_str;
			if (*format_str == '\0')
				return (-1);
			result = ft_print_arg(args, *format_str);
		}
		else
			result = write(1, format_str, 1);
		if (result == -1)
			return (-1);
		str_len += result;
		format_str++;
	}
	return (str_len);
}

int	ft_printf(const char *format_str, ...)
{
	va_list	args;
	int		str_len;

	if (!format_str)
		return (-1);
	va_start(args, format_str);
	str_len = print_format_str(format_str, args);
	va_end(args);
	return (str_len);
}
