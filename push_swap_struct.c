/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:25:45 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/12/25 17:48:15 by mzeggaf          ###   ########.fr       */
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

t_stack	*ft_create_t_stack(int *nbs, int len)
{
	t_stack	*stack;
	int		i;

	i = 0;
	stack = (t_stack *)malloc(len * sizeof(t_stack));
	if (!stack)
		return (free(nbs), exit(1), NULL);
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
	free(nbs);
	return (stack - len);
}

int	ft_stack_len(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack && len++ >= 0)
		stack = stack->next;
	return (len);
}
