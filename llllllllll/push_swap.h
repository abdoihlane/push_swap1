/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahabibi- <ahabibi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 16:53:44 by ahabibi-          #+#    #+#             */
/*   Updated: 2025/03/23 16:54:02 by ahabibi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
// # include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	int				i;
	int				index;
	int				value;

}					t_list;

typedef struct s_abdo
{
	int				len;
	void			*ptr;
}					t_abdo;

void				fswap(t_list **stack);
void				sa(t_list **stack_a);
void				sb(t_list **stack_b);
void				ss(t_list **stack_a, t_list **stack_b);
void				push(t_list **from, t_list **to);
void				pa(t_list **stack_a, t_list **stack_b);
void				pb(t_list **stack_a, t_list **stack_b);
void				idk(int len, t_list **stack_a, t_list **stack_b);

// rotate

void				rot(t_list **stack);
void				ra(t_list **stack_a);
void				rb(t_list **stack_b);
void				rr(t_list **stack_b, t_list **stack_a);

// retate && reverse

void				rev_ret(t_list **stack);
void				rra(t_list **stack_a);
void				rrb(t_list **stack_b);
void				rrr(t_list **stack_a, t_list **stack_b);

// parsing and linked list
int					has_duplicates(t_list *stack);
void				parse_and_fill_stack(int ac, char **av, t_list **stack_a);
void				add_to_stack(t_list **stack, int value);
t_list				*create_node(int value);
void				free_stack(t_list **stack);
void				free_array(char **array);
int					ft_atoi(const char *str);
int					is_invalid_sign(char *str);
char				**ft_split(const char *str, char separator);
int					ft_isdigit(int c);
void				stack_index(t_list **a);
int					ft_lstsize(t_list *lst);
int					find_smallest_position(t_list *stack);
int					alpha_or_not(char *str);
void				free_array(char **array);
void				threenu(t_list **stack_a);
void				idk(int len, t_list **stack_a, t_list **stack_b);
void				fivebocks(t_list **stack_a, t_list **stack_b);
void				fournum(t_list **stack_a, t_list **stack_b);
void				sort(t_list **a, t_list **b, int range);
void				smart_rotat(t_list **a, t_list **b);
int					max_pos(t_list *stack);
int					ft_stacklen(t_list *stack);
int					stack_max(t_list **lst);
int					find_largest_position(t_list *stack);
void				add_to_stack(t_list **stack, int value);
void				morefivebocks(t_list **stack_a, t_list **stack_b);
int					is_only_spaces(char *str);

#endif