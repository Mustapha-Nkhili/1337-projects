/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mn-khili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 21:04:24 by mn-khili          #+#    #+#             */
/*   Updated: 2025/11/13 10:31:54 by mn-khili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1337
# endif

char	*get_next_line(int fd);
char	*ft_strchr_gnl(const char *str, int c);
char	*ft_strjoin_gnl(char *buffer, char *s2);
char	*get_line(char *buffer);
char	*handle_error(char **buffer);
char	*read_until_newline(int fd, char **buffer, char *temp_str);
char	*handle_next_line(char *str);

#endif
