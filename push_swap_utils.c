/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:44:55 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/12/20 15:47:52 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted(t_stack *stack)
{
	while (stack)
	{
		if (stack->index != stack->z_index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_b)
		*stack_b = *stack_a;
	else
		(*stack_a - 1)->next = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_a - 1)->next = NULL;
	rotate_down(*stack_b);
	write(1, "pb\n", 3);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	rotate_up(*stack_b);
	*stack_a = *stack_a - 1;
	(*stack_a)->next = (*stack_a + 1);
	if (*stack_a != *stack_b)
		(*stack_a - 1)->next = NULL;
	else
		*stack_b = NULL;
	write(1, "pa\n", 3);
}

void	ft_swap(t_stack *a, t_stack *b)
{
	t_stack	c;

	c = *a;
	*a = *b;
	*b = c;
	b->next = a->next;
	a->next = b;
	a->index -= 1;
	b->index += 1;
	write(1, "sa\n", 3);
}
