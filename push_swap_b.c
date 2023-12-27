/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 17:03:02 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/12/27 19:26:41 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push_b(t_stack **a, t_stack **b)
{
	*a = (*a)->next;
	(*a - 1)->next = NULL;
	if (*b)
	{
		(*a - 2)->next = (*a - 1);
		rotate_down(*b);
	}
	else
		*b = (*a - 1);
	write(1, "pb\n", 3);
}

static int	ft_has_less_than(t_stack *stack, int num)
{
	while (stack)
	{
		if (stack->z_index < num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	ft_push_to_b(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = ft_stack_len(*a);
	if (len_a <= 3 || ft_sorted(*a))
		return ;
	while (ft_has_less_than(*a, len_a / 2))
	{
		if ((*a)->z_index < len_a / 2 && len_a--)
			ft_push_b(a, b);
		else
			ft_rx(*a, 'a');
	}
	while (len_a-- > 3)
		ft_push_b(a, b);
}
