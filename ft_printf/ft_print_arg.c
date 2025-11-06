/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-khili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 14:26:40 by mn-khili          #+#    #+#             */
/*   Updated: 2025/11/04 21:02:30 by mn-khili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_undefined_specifier(char format_s)
{
	int	write_result;

	write_result = write(1, "%", 1);
	if (write_result == -1)
		return (-1);
	if (write(1, &format_s, 1) == -1)
		return (-1);
	write_result = 2;
	return (write_result);
}

static int	putchar_pf(char c)
{
	int	write_result;

	write_result = write(1, &c, 1);
	return (write_result);
}

int	ft_print_arg(va_list args, char format_s)
{
	int	write_result;

	if (format_s == 'c')
		write_result = putchar_pf(va_arg(args, int));
	else if (format_s == 's')
		write_result = ft_putstr(va_arg(args, char *));
	else if (format_s == 'd' || format_s == 'i')
		write_result = ft_putnbr(va_arg(args, int));
	else if (format_s == 'u')
		write_result = ft_put_unsigned_nbr(va_arg(args, unsigned int));
	else if (format_s == 'x')
		write_result = ft_puthex(va_arg(args, unsigned int), 0);
	else if (format_s == 'X')
		write_result = ft_puthex(va_arg(args, unsigned int), 1);
	else if (format_s == 'p')
		write_result = ft_putvoid(va_arg(args, void *));
	else if (format_s == '%')
		write_result = write(1, "%", 1);
	else
		write_result = handle_undefined_specifier(format_s);
	return (write_result);
}
