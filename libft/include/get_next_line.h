/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalloir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:17:27 by smalloir          #+#    #+#             */
/*   Updated: 2022/12/09 03:22:10 by smalloir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*get_all_lines(int fd);
size_t	ft_strlen(const char *s);
int		ft_findchar(char c, char *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char const *s);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
