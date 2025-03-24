/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabibi- <ahabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:53:19 by ahabibi-          #+#    #+#             */
/*   Updated: 2025/03/23 16:56:39 by ahabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot(t_list **stack)
{
	t_list	*l;
	t_list	*f;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	l = *stack;
	f = *stack;
	while (l->next)
		l = l->next;
	*stack = f->next;
	f->next = NULL;
	l->next = f;
}

void	ra(t_list **stack_a)
{
	rot(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_list **stack_b)
{
	rot(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_list **stack_b, t_list **stack_a)
{
	rot(stack_b);
	rot(stack_a);
	write(1, "rr\n", 3);
}
