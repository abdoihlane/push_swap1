/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabibi- <ahabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:23:17 by ahabibi-          #+#    #+#             */
/*   Updated: 2025/02/25 22:00:00 by ahabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		x;
	char	*t;

	i = 0;
	x = 0;
	if (!s1 || !s2)
	{
		return (NULL);
	}
	t = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!t)
		return (NULL);
	while (s1[i])
		t[x++] = s1[i++];
	i = 0;
	while (s2[i])
		t[x++] = s2[i++];
	t[x] = '\0';
	return (t);
}

char	*process_substring(char **sa_ptr, char *new_sh, char *sa)
{
	size_t	len;
	char	*line;
	char	*temp;

	len = new_sh - sa;
	line = ft_substr(sa, 0, len);
	if (!line)
	{
		free(sa);
		*sa_ptr = NULL;
		return (NULL);
	}
	temp = ft_strdup(new_sh + 1);
	if (!temp)
	{
		free(line);
		free(sa);
		*sa_ptr = NULL;
		return (NULL);
	}
	free(sa);
	*sa_ptr = temp;
	return (line);
}

char	*read_s(int fd, char *buff, char *sa)
{
	ssize_t	num_byte;
	char	*temp;

	(num_byte = read(fd, buff, BUFFER_SIZE));
	while (num_byte > 0)
	{
		buff[num_byte] = '\0';
		temp = ft_strjoin(sa, buff);
		if (!temp)
		{
			free(sa);
			return (NULL);
		}
		free(sa);
		sa = temp;
		if (ft_strchr(buff, '\n'))
			break ;
		num_byte = read(fd, buff, BUFFER_SIZE);
	}
	if (num_byte < 0)
	{
		free(sa);
		sa = NULL;
	}
	return (sa);
}

void	*find_new(char **sa_ptr)
{
	char	*sa;
	char	*line;
	char	*new_sh;

	sa = *sa_ptr;
	new_sh = ft_strchr(sa, '\n');
	if (new_sh)
	{
		line = process_substring(sa_ptr, new_sh, sa);
		if (line && line[0] == '\0')
		{
			free(line);
			//return NULL;
		}
		return (line);
	}
	line = ft_strdup(sa);
	free(sa);
	if (!line)
	{
		*sa_ptr = NULL;
		return (NULL);
	}
	*sa_ptr = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*sa;
	char		*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	if (!sa)
		sa = ft_strdup("");
	sa = read_s(fd, buff, sa);
	free(buff);
	if (!sa || *sa == '\0')
	{
		free(sa);
		sa = NULL;
		return (NULL);
	}
	line = find_new(&sa);
	if(line == NULL)
		{
			free(line);
			return (NULL);
		}
	return (line);
}
