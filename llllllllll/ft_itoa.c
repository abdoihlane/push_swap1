/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabibi- <ahabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:52:27 by ahabibi-          #+#    #+#             */
/*   Updated: 2025/03/23 16:52:31 by ahabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	count(int nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		count++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

char	*itoati(int nbr)
{
	char	*str;
	int		i;
	int		counto;

	i = 0;
	counto = count(nbr);
	str = malloc(sizeof(char) * counto);
	if (nbr < 0)
	{
		str[i] = '-';
		nbr *= -1;
		i++;
	}
	while (counto > i)
	{
		str[i] = (nbr % 10) + '0';
		i++;
	}
	str[i] = '\0';
	return (str);
}
