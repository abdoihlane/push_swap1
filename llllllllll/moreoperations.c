/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moreoperations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabibi- <ahabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:52:54 by ahabibi-          #+#    #+#             */
/*   Updated: 2025/03/23 16:52:55 by ahabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	morefivebocks(t_list **stack_a, t_list **stack_b)
{
	int	posi;

	posi = find_smallest_position(*stack_a);
	if (posi == 3)
	{
		rra(stack_a);
		rra(stack_a);
		pb(stack_a, stack_b);
		fournum(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	else if (posi == 4)
	{
		rra(stack_a);
		pb(stack_a, stack_b);
		fournum(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	if (posi == 0)
	{
		pb(stack_a, stack_b);
		fournum(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}

void	fivebocks(t_list **stack_a, t_list **stack_b)
{
	int	posi;

	posi = find_smallest_position(*stack_a);
	if (posi == 0)
		morefivebocks(stack_a, stack_b);
	else if (posi == 1)
	{
		ra(stack_a);
		pb(stack_a, stack_b);
		fournum(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	else if (posi == 2)
	{
		ra(stack_a);
		sa(stack_a);
		pb(stack_a, stack_b);
		fournum(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
	else if (posi == 3)
		morefivebocks(stack_a, stack_b);
	else if (posi == 4)
		morefivebocks(stack_a, stack_b);
}

void	morethree(t_list **stack_a)
{
	t_list	*uno;
	t_list	*dos;
	t_list	*third;

	uno = *stack_a;
	dos = (*stack_a)->next;
	third = (*stack_a)->next->next;
	if (uno->content < dos->content && third->content < dos->content
		&& third->content < uno->content)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (uno->content > dos->content && third->content < dos->content
		&& third->content < uno->content)
	{
		ra(stack_a);
		sa(stack_a);
	}
	else if (uno->content < dos->content && dos->content > third->content
		&& third->content > uno->content)
	{
		sa(stack_a);
		ra(stack_a);
	}
}

void	threenu(t_list **stack_a)
{
	t_list	*uno;
	t_list	*dos;
	t_list	*third;

	uno = *stack_a;
	dos = (*stack_a)->next;
	third = (*stack_a)->next->next;
	if (ft_lstsize(*stack_a) < 3)
		return ;
	if (uno->content > dos->content && third->content > dos->content
		&& third->content < uno->content)
		ra(stack_a);
	else if (uno->content < dos->content && third->content < dos->content
		&& third->content < uno->content)
		morethree(stack_a);
	else if (uno->content > dos->content && third->content > dos->content
		&& third->content > uno->content)
		sa(stack_a);
	else if (uno->content > dos->content && third->content < dos->content
		&& third->content < uno->content)
		morethree(stack_a);
	else if (uno->content < dos->content && dos->content > third->content
		&& third->content > uno->content)
		morethree(stack_a);
}
