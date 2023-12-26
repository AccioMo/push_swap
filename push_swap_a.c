/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 17:12:39 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/12/26 02:53:34 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_costs(t_stack *a, t_stack *b, int len_a, int len_b)
{
	int	i;

	i = 0;
	while (b)
	{
		b->costb = ft_short(i, len_b);
		b->costa = ft_short(ft_get_larger(a, (b)->z_index), len_a);
		b = b->next;
		i++;
	}
}

t_stack	*ft_barter(t_stack *stack)
{
	t_stack	*best;
	int		to_best;
	int		to_stack;

	best = stack;
	while (stack)
	{
		to_best = ft_abs(best->costa) + ft_abs(best->costb);
		to_stack = ft_abs(stack->costa) + ft_abs(stack->costb);
		if (to_stack < to_best)
			best = stack;
		stack = stack->next;
	}
	return (best);
}

void	ft_push_a(t_stack **a, t_stack **b)
{
	int	len_b;

	if (!b)
		return ;
	len_b = ft_stack_len(*b);
	rotate_up(*b);
	(*b + len_b - 1)->next = *a;
	*a -= 1;
	if (*a == *b)
		*b = NULL;
	else
		(*b + len_b - 2)->next = NULL;
	write(1, "pa\n", 3);
}

void	ft_push_to_a(t_stack **a, t_stack **b)
{
	t_stack	*best;
	int		len_a;
	int		len_b;

	len_a = 3;
	len_b = ft_stack_len(*b);
	while (len_b)
	{
		ft_get_costs(*a, *b, len_a, len_b);
		best = ft_barter(*b);
		ft_full_rotate(*a, *b, best->costa, best->costb);
		ft_push_a(a, b);
		len_a++;
		len_b--;
	}
}
