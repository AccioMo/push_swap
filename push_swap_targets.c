/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_targets.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 17:43:04 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/12/26 01:27:11 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_larger(t_stack *stack, int z)
{
	t_stack	*head;
	int		x;
	int		i;

	i = 0;
	x = INT_MAX;
	head = stack;
	while (stack)
	{
		if (stack->z_index < x && stack->z_index > z)
			x = stack->z_index;
		stack = stack->next;
	}
	if (x == INT_MAX)
		return (ft_get_larger(head, -1));
	while (head && head->z_index != x && i++ >= 0)
		head = head->next;
	return (i);
}

int	ft_get_smaller(t_stack *stack, int z)
{
	t_stack	*head;
	int		x;
	int		i;

	i = 0;
	x = -1;
	head = stack;
	while (stack)
	{
		if (stack->z_index > x && stack->z_index < z)
			x = stack->z_index;
		stack = stack->next;
	}
	if (x == -1)
		return (ft_get_smaller(head, INT_MAX));
	while (head && head->z_index != x && i++ >= 0)
		head = head->next;
	return (i);
}

int	ft_get_target(t_stack *stack, int index)
{
	int	len;

	len = ft_stack_len(stack);
	if (index < 0)
		return (ft_short((stack + (len - 1))->index, len));
	else if (index >= len)
		return (ft_short(stack->index, len));
	while (stack && stack->z_index != index)
		stack = stack->next;
	return (ft_short(stack->index, len));
}

void	ft_sort_three(t_stack *stack)
{
	if (stack->z_index < stack->next->z_index)
	{
		if (stack->next->z_index > stack->next->next->z_index)
			ft_rrx(stack, 'a');
	}
	else if (stack->z_index > stack->next->next->z_index)
		ft_rx(stack, 'a');
	if (stack->z_index > stack->next->z_index)
		ft_sa(stack, stack->next);
}

int	ft_is_int_max(char *str)
{
	char	*int_max;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	int_max = "2147483647";
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
		{
			int_max = "2147483648";
			sign = -1;
		}
	}
	while (*str == '0')
		str++;
	while (*(str + i) >= '0' && *(str + i) <= '9')
		i++;
	while (*str >= '0' && *str <= '9' && i == 10)
	{
		if (*str++ > *int_max++)
			return (0);
	}
	return ((i <= 10) * sign);
}
