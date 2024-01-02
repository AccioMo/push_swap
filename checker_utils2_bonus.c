/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 03:19:29 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/02 23:45:54 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_stack *one)
{
	t_stack	c;
	t_stack	*two;

	if (!one || !(one->next))
		return ;
	two = one->next;
	c = *one;
	*one = *two;
	*two = c;
	two->next = one->next;
	one->next = two;
	one->index -= 1;
	two->index += 1;
}

void	swap_both(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}

void	push_a(t_stack **a, t_stack **b)
{
	t_stack	*a_start;
	t_stack	*b_end;

	if (!*b)
		return ;
	rotate(*b);
	b_end = *b;
	if (!(b_end->next))
	{
		(*b)->next = *a;
		*a = *b;
		*b = NULL;
		return ;
	}
	while (b_end->next->next)
		b_end = b_end->next;
	a_start = b_end->next;
	b_end->next = NULL;
	a_start->next = *a;
	*a = a_start;
}

void	push_b(t_stack **a, t_stack **b)
{
	t_stack	*b_clone;
	t_stack	*b_end;

	if (!*a)
		return ;
	b_clone = *b;
	b_end = *a;
	*a = (*a)->next;
	b_end->next = NULL;
	if (*b)
	{
		while (b_clone->next)
			b_clone = b_clone->next;
		b_clone->next = b_end;
		reverse_rotate(*b);
	}
	else
		*b = b_end;
}
