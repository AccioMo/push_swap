/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 03:10:44 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/12/28 00:25:52 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rotate(t_stack *stack)
{
	if (!stack)
		return ;
	while (stack->next)
	{
		swap(stack);
		stack = stack->next;
	}
}

void	reverse_rotate(t_stack *stack)
{
	t_stack	*head;

	if (!stack)
		return ;
	head = stack;
	while (stack->next)
		stack = stack->next;
	while (stack-- != head)
		swap(stack);
}

void	rotate_both(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}

void	reverse_rotate_both(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
