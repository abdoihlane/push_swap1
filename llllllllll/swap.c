/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabibi- <ahabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:53:30 by ahabibi-          #+#    #+#             */
/*   Updated: 2025/03/23 17:00:02 by ahabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fswap(t_list **stack)
{
	t_list	*uno;
	t_list	*dos;

	uno = *stack;
	dos = (*stack)->next;
	uno->next = dos->next;
	dos->next = uno;
	*stack = dos;
}

void	sa(t_list **stack_a)
{
	fswap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_list **stack_b)
{
	fswap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	fswap(stack_a);
	fswap(stack_b);
	write(1, "ss\n", 3);
}
