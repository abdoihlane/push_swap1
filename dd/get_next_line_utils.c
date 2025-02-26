/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabibi- <ahabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:23:31 by ahabibi-          #+#    #+#             */
/*   Updated: 2025/02/25 21:31:05 by ahabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*copy;

	i = 0;
	copy = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!copy)
		return (NULL);
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*allocate_empty_str(void)
{
	char	*s;

	s = malloc(1);
	if (!s)
		return (NULL);
	s[0] = '\0';
	return (s);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	str_len;
	size_t	i;
	char	*s;

	if (!str)
		return (NULL);
	str_len = ft_strlen(str);
	i = 0;
	if (start >= str_len)
		return (allocate_empty_str());
	if (start + len > str_len)
	{
		len = str_len - start;
	}
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	while (i < len)
	{
		s[i] = str[start + i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
