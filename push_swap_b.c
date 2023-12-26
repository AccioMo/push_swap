/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 17:03:02 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/12/26 04:46:52 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_first_small(t_stack *stack, int len, int z)
{
	int		x;
	int		i;

	x = -1;
	i = 0;
	while (stack)
	{
		if (x == -1 && stack->z_index < z)
			x = i;
		else if ((len - i) > 0 && len - i < x && stack->z_index < z)
			x = i;
		stack = stack->next;
		i++;
	}
	if (x == -1)
		return (z);
	return (x);
}

void	ft_push_b(t_stack **a, t_stack **b)
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

void	ft_push_to_b(t_stack **a, t_stack **b)
{
	int	cost;
	int	len_a;
	int	len_b;
	int	pivot;
	int	chunk_size;

	len_a = ft_stack_len(*a);
	len_b = 0;
	chunk_size = len_a / 2;
	pivot = chunk_size;
	while (len_a > 3)
	{
		cost = ft_get_first_small(*a, len_a, pivot);
		if (cost == pivot)
			pivot += chunk_size;
		cost = ft_short(cost, len_a);
		ft_rotate(*a, cost, 'a');
		if (ft_sorted(*a) && *b == NULL)
			return ;
		ft_push_b(a, b);
		len_a--;
		len_b++;
	}
}
