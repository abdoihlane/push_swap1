/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabibi- <ahabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:52:45 by ahabibi-          #+#    #+#             */
/*   Updated: 2025/03/24 15:49:48 by ahabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	has_duplicates(t_list *stack)
{
	t_list	*current;
	t_list	*check;

	current = stack;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->content == check->content)
				return (1);
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}

int	alpha_or_not(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			return (1);
		if (str[i] >= 'A' && str[i] <= 'Z')
			return (1);
		if (str[i] < '0' && str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void	stack_index(t_list **a)
{
	t_list	*current;
	t_list	*next;

	current = *a;
	while (current)
	{
		current->index = 0;
		next = *a;
		while (next)
		{
			if (current->content > next->content)
				current->index++;
			next = next->next;
		}
		current = current->next;
	}
}

int	max_pos(t_list *stack)
{
	int	i;
	int	max;

	i = 0;
	max = stack_max(&stack);
	while (stack)
	{
		if (stack->content == max)
			return (i);
		i++;
		stack = stack->next;
	}
	return (i);
}

void	smart_rotat(t_list **a, t_list **b)
{
	int	mid;
	int	max;
	int	max_poss;

	while (*b)
	{
		max = stack_max(b);
		while ((*b)->content != max)
		{
			mid = ft_stacklen(*b) / 2;
			max_poss = max_pos(*b);
			if (max_poss <= mid)
				rb(b);
			else
				rrb(b);
		}
		pa(a, b);
	}
}
