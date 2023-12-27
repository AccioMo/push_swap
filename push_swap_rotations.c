/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:35:50 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/12/27 18:07:58 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rr(t_stack *a, t_stack *b)
{
	rotate_up(a);
	rotate_up(b);
	write(1, "rr\n", 3);
}

static void	ft_rrr(t_stack *a, t_stack *b)
{
	rotate_down(a);
	rotate_down(b);
	write(1, "rrr\n", 4);
}

void	ft_rotate(t_stack *stack, int r, char s)
{
	if (r < 0)
	{
		while (r++)
			ft_rrx(stack, s);
	}
	else
	{
		while (r--)
			ft_rx(stack, s);
	}
}

void	ft_full_rotate(t_stack *a, t_stack *b, int costa, int costb)
{
	while (costa > 0 && costb > 0)
	{
		ft_rr(a, b);
		costa--;
		costb--;
	}
	while (costa < 0 && costb < 0)
	{
		ft_rrr(a, b);
		costa++;
		costb++;
	}
	ft_rotate(a, costa, 'a');
	ft_rotate(b, costb, 'b');
}
