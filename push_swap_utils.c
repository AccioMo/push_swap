/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:44:55 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/12/14 18:19:50 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sorted(int *array, int len)
{
	while (len-- > 1)
	{
		if (*array > *(array + 1))
			return (0);
		array++;
	}
	return (1);
}

int	ft_push(int *nbs, int len)
{
	if (!ft_sorted(nbs, len))
		return (write(1, "pb\n", 3));
	else
		return (0);
}

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
	write(1, "sa\n", 3);
}
