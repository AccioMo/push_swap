/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 03:19:29 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/12/26 04:18:48 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_stack *a, t_stack *b)
{
	t_stack	c;

	if (!a || !b)
		return ;
	c = *a;
	*a = *b;
	*b = c;
	b->next = a->next;
	a->next = b;
	a->index -= 1;
	b->index += 1;
}

void	swap_both(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	swap(a, a->next);
	swap(b, b->next);
}

void	push_a(t_stack **a, t_stack **b)
{
	int	len_b;

	if (!*b)
		return ;
	len_b = ft_stack_len(*b);
	rotate(*b);
	(*b + len_b - 1)->next = *a;
	*a -= 1;
	if (*a == *b)
		*b = NULL;
	else
		(*b + len_b - 2)->next = NULL;
}

void	push_b(t_stack **a, t_stack **b)
{
	if (!*a)
		return ;
	*a = (*a)->next;
	(*a - 1)->next = NULL;
	if (*b)
	{
		(*a - 2)->next = (*a - 1);
		reverse_rotate(*b);
	}
	else
		*b = (*a - 1);
}
