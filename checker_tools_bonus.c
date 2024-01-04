/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_tools_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 03:20:38 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/04 18:08:30 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

int	ft_sorted(t_stack *stack)
{
	while (stack)
	{
		if (stack->index != stack->z_index)
			return (0);
		stack = stack->next;
	}
	return (1);
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
