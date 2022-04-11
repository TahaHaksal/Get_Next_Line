/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaksal <m.haksal@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 09:34:57 by mhaksal           #+#    #+#             */
/*   Updated: 2022/03/01 12:26:53 by mhaksal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!*s && c == '\0')
		return ((char *)s);
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		if (s[i + 1] == '\0' && c == '\0')
			return ((char *)s + i + 1);
		i++;
	}
	return (NULL);
}

static char	*_fore(char *ptr)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!ptr)
		return (NULL);
	while (ptr[i] != '\0' && ptr[i] != '\n')
		i++;
	if (ptr[i] == '\n')
		i++;
	tmp = malloc(i + 1);
	ft_strlcpy(tmp, ptr, i + 1);
	return (tmp);
}

static char	*_after(char *ptr)
{
	char	*tmp;
	int		i;

	i = 0;
	while (ptr[i] != '\0' && ptr[i] != '\n')
		i++;
	if (ptr[i + 1] && ptr[i])
	{
		tmp = ft_strdup(&ptr[i + 1]);
		free(ptr);
		return (tmp);
	}
	if (ptr)
		free(ptr);
	return (NULL);
}

static char	*_save(int fd, char	*ptr)
{
	char	*buffer;
	int		a;

	buffer = malloc(BUFFER_SIZE + 1);
	a = read(fd, buffer, BUFFER_SIZE);
	while (a > 0)
	{
		buffer[a] = '\0';
		ptr = ft_strjoin(ptr, buffer);
		if (ft_strchr(ptr, '\n'))
		{
			free(buffer);
			return (ptr);
		}
		a = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (ptr)
		return (ptr);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*ptr[4096];
	char		*tmp;

	if (!ptr[fd] || !ft_strchr(ptr[fd], '\n'))
		ptr[fd] = _save(fd, ptr[fd]);
	if (!ptr[fd])
		return (NULL);
	tmp = _fore(ptr[fd]);
	ptr[fd] = _after(ptr[fd]);
	return (tmp);
}
