/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabibi- <ahabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:34:05 by ahabibi-          #+#    #+#             */
/*   Updated: 2025/03/01 15:28:51 by ahabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	count_separator(char c, char separator)
{
	return (c == separator);
}

int	count_word(const char *str, char separator)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && count_separator(*str, separator))
			str++;
		if (*str)
			count++;
		while (*str && !count_separator(*str, separator))
			str++;
	}
	return (count);
}

char	*get_next_word(const char *str, char separator)
{
	int		len;
	char	*word;
	int		i;

	len = 0;
	while (str[len] && !count_separator(str[len], separator))
		len++;
	word = (char *)malloc((len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

char	*free_tab(char **tab, int i)
{
	while (i > 0)
		free(tab[--i]);
	free(tab);
	return (NULL);
}

char	**ft_split(const char *str, char separator)
{
	char	**tab;
	int		word_count;
	int		i;

	word_count = count_word(str, separator);
	tab = (char **)malloc((word_count + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str && count_separator(*str, separator))
			str++;
		if (*str)
		{
			tab[i] = get_next_word(str, separator);
			if (tab[i] == NULL)
				return (free_tab(tab, i), NULL);
			i++;
		}
		while (*str && !count_separator(*str, separator))
			str++;
	}
	tab[i] = NULL;
	return (tab);
}
