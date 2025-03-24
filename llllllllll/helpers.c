/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabibi- <ahabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:52:40 by ahabibi-          #+#    #+#             */
/*   Updated: 2025/03/23 16:59:06 by ahabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	find_smallest_position(t_list *stack)
{
	int		min_value;
	int		position;
	int		min_position;
	t_list	*current;

	if (!stack)
		return (-1);
	min_value = stack->content;
	position = 0;
	min_position = 0;
	current = stack;
	while (current)
	{
		if (current->content < min_value)
		{
			min_value = current->content;
			min_position = position;
		}
		current = current->next;
		position++;
	}
	return (min_position);
}

int	is_only_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	is_invalid_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		is_only_spaces(str);
		if ((str[i] == '-' || str[i] == '+') && (str[i + 1] == '-' || str[i
					+ 1] == '+'))
			return (1);
		if (!ft_isdigit(str[i + 1]))
			return (1);
		if (str[0] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	long	result;

	int (i), (sign);
	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	return ((int)(result * sign));
}
