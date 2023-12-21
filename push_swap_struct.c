/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:25:45 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/12/21 13:57:00 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_z_index(int *nbs, int target, int len)
{
	int	z;

	z = 0;
	while (len--)
	{
		if (*nbs++ < target)
			z++;
	}
	return (z);
}

static t_stack	*get_target(t_stack *stack, int index)
{
	if (index < 0)
		return (NULL);
	while (stack && stack->z_index != index)
		stack = stack->next;
	return (stack);
}

static t_stack	*get_closest(t_stack *before, t_stack *after, int len)
{
	if (!before)
		return (after);
	else if (!after)
		return (before);
	if (before->index < after->index)
	{
		if (len - after->index < before->index)
			return (after);
		else
			return (before);
	}
	else
	{
		if (len - before->index < after->index)
			return (before);
		else
			return (after);
	}
}

static t_stack	*ft_get_target(t_stack *stack, int len)
{
	t_stack	*before;
	t_stack	*after;

	before = get_target(stack, stack->z_index - 1);
	after = get_target(stack, stack->z_index + 1);
	return (get_closest(before, after, len));
}

void	ft_get_costs(t_stack *stack, int len)
{
	stack->z_cost = stack->z_index - (stack->z_index > len / 2) * len;
	stack->target = ft_get_target(stack, len);
	stack->t_cost = stack->target->index - (stack->target->index > len / 2) * len ;
	stack = stack->next;
}

t_stack	*ft_create_t_stack(int *nbs, int len)
{
	t_stack	*stack;
	int		i;

	i = 0;
	stack = (t_stack *)malloc(len * sizeof(t_stack));
	while (i < len)
	{
		stack->nb = *(nbs + i);
		stack->index = i;
		stack->z_index = get_z_index(nbs, stack->nb, len);
		stack->next = stack + 1;
		if (i + 1 == len)
			stack->next = NULL;
		stack++;
		i++;
	}
	return (stack - len);
}
