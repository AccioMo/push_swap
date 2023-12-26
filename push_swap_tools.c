/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 17:05:31 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/12/26 04:44:59 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_short(int nbr, int len)
{
	return (nbr - (nbr > len / 2) * len);
}

int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

void	swap(t_stack *a, t_stack *b)
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
