/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 03:10:44 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/12/26 03:55:03 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	rotate(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		swap(stack, stack->next);
		stack = stack->next;
	}
	return (0);
}

int	reverse_rotate(t_stack *stack)
{
	t_stack	*head;
	int		len;

	if (!stack)
		return (1);
	len = 0;
	head = stack;
	while (stack->next)
		stack = stack->next;
	while (stack-- != head)
		swap(stack, stack->next);
	return (0);
}

int	rotate_both(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return (1);
	rotate(a);
	rotate(b);
	return (0);
}

int	reverse_rotate_both(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return (1);
	reverse_rotate(a);
	reverse_rotate(b);
	return (0);
}
