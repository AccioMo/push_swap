/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_functions_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 04:05:37 by mzeggaf           #+#    #+#             */
/*   Updated: 2024/01/04 20:49:11 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	ft_status_code(t_stack **a, t_stack **b, char *istr)
{
	if (!ft_strncmp(istr, "sa\n", -1))
		swap(*a);
	else if (!ft_strncmp(istr, "sb\n", -1))
		swap(*b);
	else if (!ft_strncmp(istr, "ss\n", -1))
		swap_both(*a, (*b));
	else if (!ft_strncmp(istr, "ra\n", -1))
		rotate(*a);
	else if (!ft_strncmp(istr, "rb\n", -1))
		rotate(*b);
	else if (!ft_strncmp(istr, "rra\n", -1))
		reverse_rotate(*a);
	else if (!ft_strncmp(istr, "rrb\n", -1))
		reverse_rotate(*b);
	else if (!ft_strncmp(istr, "rr\n", -1))
		rotate_both(*a, (*b));
	else if (!ft_strncmp(istr, "rrr\n", -1))
		reverse_rotate_both(*a, (*b));
	else if (!ft_strncmp(istr, "pa\n", -1))
		push_a(a, b);
	else if (!ft_strncmp(istr, "pb\n", -1))
		push_b(a, b);
	else
		return (1);
	return (0);
}

int	ft_apply_instructions(t_stack *a, t_stack *b)
{
	t_stack	*anchor;
	char	*istr;

	anchor = a;
	istr = "";
	while (istr)
	{
		istr = get_next_line(0);
		if (istr && ft_status_code(&a, &b, istr) == 1)
			return (free(istr), free(anchor), write(2, "Error\n", 6));
		free(istr);
	}
	if (ft_sorted(a) && b == NULL)
		return (free(anchor), write(1, "OK\n", 3));
	else
		return (free(anchor), write(1, "KO\n", 3));
}
