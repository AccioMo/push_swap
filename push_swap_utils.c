/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:44:55 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/12/25 17:09:20 by mzeggaf          ###   ########.fr       */
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

void	ft_sb(t_stack *a, t_stack *b)
{
	swap(a, b);
	write(1, "sb\n", 3);
}

void	ft_sa(t_stack *a, t_stack *b)
{
	swap(a, b);
	write(1, "sa\n", 3);
}

void	ft_rx(t_stack *stack, char s)
{
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
