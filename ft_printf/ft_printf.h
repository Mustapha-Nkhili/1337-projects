/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-khili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:39:53 by mn-khili          #+#    #+#             */
/*   Updated: 2025/11/04 21:07:27 by mn-khili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format_str, ...);
int		ft_putstr(const char *str);
int		ft_putnbr(int n);
int		ft_print_arg(va_list args, char format_s);
int		ft_put_unsigned_nbr(unsigned int n);
int		ft_puthex(size_t n, int is_upper_format);
int		ft_putvoid(void *p);
char	*ft_utoa(unsigned int n);

#endif
