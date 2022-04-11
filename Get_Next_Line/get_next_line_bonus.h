/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 09:35:01 by mhaksal           #+#    #+#             */
/*   Updated: 2022/02/28 09:39:06 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		ft_strlen(const char *s);
char	*ft_strdup(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *left_str, char *buff);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		f_strchck(char *s, char c);

#endif
