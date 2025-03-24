/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabibi- <ahabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:53:05 by ahabibi-          #+#    #+#             */
/*   Updated: 2025/03/23 16:54:36 by ahabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_node(int value)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = value;
	new_node->next = NULL;
	return (new_node);
}

void	lst_addback(t_list **lst, t_list *node)
{
	t_list	*tmp;

	if (!node)
		return ;
	if (!*lst)
	{
		*lst = node;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = node;
}

void	add_to_stack(t_list **stack, int value)
{
	int		i;
	t_list	*new_node;

	i = 0;
	new_node = create_node(value);
	if (!new_node)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	lst_addback(stack, new_node);
	i++;
}
