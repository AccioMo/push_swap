/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:44:55 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/12/17 23:31:55 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sorted(t_stack *stack)
{
	while (stack)
	{
		// ft_printf("\n%d, %d\n", stack->index, stack->z_index);
		if (stack->index != stack->z_index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_push(t_stack *stack)
{
	if (!ft_sorted(stack))
		return (write(1, "pb\n", 3));
	else
		return (0);
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
	b->index +=1;
	write(1, "sa\n", 3);
}
