/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <almichel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 23:53:35 by almichel          #+#    #+#             */
/*   Updated: 2025/01/22 23:53:35 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/types.h>
// # include <sys/uio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft__strlen(const char *str);
int		check_malloc(char *buffer);

char	*get_next_line(int fd, bool tofree);
char	*clean_stock(char *str, size_t i, size_t k);
char	*new_line(char *str);
char	*ft__strjoin(char *s1, char *s2);

#endif