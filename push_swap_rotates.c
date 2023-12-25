/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 11:17:07 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/12/25 17:55:49 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack)
{
	// if (stack->z_index == stack->next->z_index + 1)
		// ft_swap(stack, stack->next);
	rotate_up(stack);
	write(1, "ra\n", 3);
}

void	rra(t_stack *stack)
{
	// if (stack->z_index == stack->next->z_index + 1)
		// ft_swap(stack, stack->next);
	rotate_down(stack);
	write(1, "rra\n", 4);
}

void	rb(t_stack *stack)
{
	// if (stack->z_index == stack->next->z_index + 1)
		// ft_swap(stack, stack->next);
	rotate_up(stack);
	write(1, "rb\n", 3);
}

void	rrb(t_stack *stack)
{
	// if (stack->z_index == stack->next->z_index + 1)
		// ft_swap(stack, stack->next);
	rotate_down(stack);
	write(1, "rrb\n", 4);
}