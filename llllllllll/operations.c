/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabibi- <ahabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:52:59 by ahabibi-          #+#    #+#             */
/*   Updated: 2025/03/23 16:53:00 by ahabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list **a, t_list **b, int range)
{
	int	i;

	i = 0;
	while (*a)
	{
		if ((*a)->index < i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if ((*a)->index < (i + range))
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
	smart_rotat(a, b);
}

void	morefor(t_list **stack_a, t_list **stack_b, int posi)
{
	if (posi == 2)
	{
		ra(stack_a);
		sa(stack_a);
		pb(stack_a, stack_b);
		threenu(stack_a);
		pa(stack_a, stack_b);
	}
	else if (posi == 3)
	{
		rra(stack_a);
		pb(stack_a, stack_b);
		threenu(stack_a);
		pa(stack_a, stack_b);
	}
}

void	fournum(t_list **stack_a, t_list **stack_b)
{
	int	posi;

	posi = 0;
	posi = find_smallest_position(*stack_a);
	if (posi == 0)
	{
		pb(stack_a, stack_b);
		threenu(stack_a);
		pa(stack_a, stack_b);
	}
	else if (posi == 1)
	{
		ra(stack_a);
		pb(stack_a, stack_b);
		threenu(stack_a);
		pa(stack_a, stack_b);
	}
	else if (posi == 2)
		morefor(stack_a, stack_b, posi);
	else if (posi == 3)
		morefor(stack_a, stack_b, posi);
}

void	two(t_list **stack_a)
{
	int	posi;

	posi = find_smallest_position(*stack_a);
	if (posi == 1)
		sa(stack_a);
}

void	idk(int len, t_list **stack_a, t_list **stack_b)
{
	if (len == 2)
		two(stack_a);
	if (len == 3)
		threenu(stack_a);
	if (len == 4)
		fournum(stack_a, stack_b);
	if (len == 5)
		fivebocks(stack_a, stack_b);
	else if (len > 5)
		sort(stack_a, stack_b, 30);
}
