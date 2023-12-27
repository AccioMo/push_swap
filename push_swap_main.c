/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:39:21 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/12/27 18:04:20 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = ft_get_stack(argc, argv);
	stack_b = NULL;
	ft_push_to_b(&stack_a, &stack_b);
	if (ft_stack_len(stack_a) == 3)
		ft_sort_three(stack_a);
	ft_push_to_a(&stack_a, &stack_b);
	ft_rotate(stack_a, ft_get_target(stack_a, 0), 'a');
	free(stack_a);
	return (0);
}
