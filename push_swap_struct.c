/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:25:45 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/12/20 19:28:55 by mzeggaf          ###   ########.fr       */
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

void	get_t_stack_costs(t_stack *stack, int len)
{
	while (stack)
	{
		stack->t_index = ft_get_target(stack, len);
		
		stack = stack->next;
	}
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
	get_t_stack_costs(stack - len, len);
	return (stack - len);
}
