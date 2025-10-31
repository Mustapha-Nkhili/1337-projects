/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-khili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:47:18 by mn-khili          #+#    #+#             */
/*   Updated: 2025/10/27 21:34:31 by mn-khili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*data;
	size_t	data_size;

	data_size = nmemb * size;
	if (nmemb != 0 && data_size / nmemb != size)
		return (NULL);
	if (data_size == 0)
		data_size = 1;
	data = malloc(data_size);
	if (data == NULL)
		return (NULL);
	ft_bzero(data, data_size);
	return (data);
}
