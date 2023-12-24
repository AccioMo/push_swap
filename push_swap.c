/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:35:50 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/12/24 16:55:36 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *a, t_stack *b)
{
	t_stack	c;

	c = *a;
	*a = *b;
	*b = c;
	b->next = a->next;
	a->next = b;
	a->index -= 1;
	b->index += 1;
}

void	rotate_up(t_stack *stack)
{
	while (stack->next)
	{
		swap(stack, stack->next);
		stack = stack->next;
	}
}

void	rotate_down(t_stack *stack)
{
	t_stack	*head;
	int		len;

	len = 0;
	head = stack;
	while (stack->next)
		stack = stack->next;
	while (stack-- != head)
		swap(stack, stack->next);
}

void	ft_rx(t_stack *stack, char s)
{
	// if (stack->z_index == stack->next->z_index + 1)
		// ft_swap(stack, stack->next);
	rotate_up(stack);
	write(1, "r", 1);
	write(1, &s, 1);
	write(1, "\n", 1);
}

void	ft_rrx(t_stack *stack, char s)
{
	rotate_down(stack);
	write(1, "rr", 2);
	write(1, &s, 1);
	write(1, "\n", 1);
}
