/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabibi- <ahabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:53:27 by ahabibi-          #+#    #+#             */
/*   Updated: 2025/03/24 21:26:44 by ahabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	frexit(t_list **stack_a)
{
	write(2, "Error\n", 6);
	free_stack(stack_a);
	exit(1);
}

void	parse_and_fill_stack(int ac, char **av, t_list **stack_a)
{
	char	**split;

	int (i), (j), (len);
	i = 1;
	len = 0;
	while (i < ac)
	{
		if (!av[i] || av[i][0] == '\0' || is_only_spaces(av[i]))
			frexit(stack_a);
		split = ft_split(av[i], ' ');
		j = 0;
		while (split[j])
		{
			if (!is_invalid_sign(split[j]) || !ft_isdigit(split[j][0])
				|| alpha_or_not(split[j]) || split[j][0] == '\0')
					frexit(stack_a);
			add_to_stack(stack_a, ft_atoi(split[j]));
			j++;
			len++;
		}
		free_array(split);
		i++;
	}
	if (has_duplicates(*stack_a) || len < 2)
		frexit(stack_a);
}

int	find_largest_position(t_list *stack)
{
	int		max_value;
	int		position;
	int		index;
	t_list	*temp;

	if (!stack)
		return (-1);
	max_value = stack->content;
	position = 0;
	index = 0;
	temp = stack;
	while (temp)
	{
		if (temp->content > max_value)
		{
			max_value = temp->content;
			position = index;
		}
		temp = temp->next;
		index++;
	}
	return (position);
}

int	stack_max(t_list **lst)
{
	t_list	*current;
	int		max;

	current = *lst;
	max = current->content;
	while (current)
	{
		if (current->content > max)
			max = current->content;
		current = current->next;
	}
	return (max);
}

int	ft_stacklen(t_list *stack)
{
	int	len;

	len = 0;
	while (stack != NULL)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}
