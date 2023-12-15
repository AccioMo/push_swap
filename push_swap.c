/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:35:50 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/12/15 19:56:31 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

static void	rotate_up(int *array, int len)
{
	int	i;

	i = 0;
	while (i++ < len - 1)
		swap((array + i - 1), (array + i));
}

static void	rotate_down(int *array, int len)
{
	while (len-- > 1)
		swap((array + len - 1), (array + len));
}

void	ra(int *nbrs, int len)
{
	if (*nbrs < *(nbrs + 1))
		ft_swap(nbrs, (nbrs + 1));
	rotate_up(nbrs, len);
	write(1, "ra\n", 3);
}

void	rra(int *nbrs, int len)
{
	if (*nbrs > *(nbrs + 1))
		ft_swap(nbrs, (nbrs + 1));
	rotate_down(nbrs, len);
	write(1, "rra\n", 4);
}
