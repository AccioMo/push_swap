/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 01:39:58 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/12/26 04:06:14 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_print_stack(t_stack *stack)
{
	ft_printf("___________\n");
	while (stack)
	{
		ft_printf("| %d: i: %d |\n", stack->nb, stack->index);
		stack = stack->next;
	}
	ft_printf("___________\n");
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*buffer;
	char	*tmp;
	char	**istr;

	tmp = NULL;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	buffer[BUFFER_SIZE] = '\0';
	stack_a = ft_get_stack(argc, argv);
	stack_b = NULL;
	while (buffer)
	{
		buffer = ft_read(0, buffer);
		tmp = ft_fstrjoin(tmp, buffer);
	}
	istr = ft_split(tmp, '\n');
	ft_apply_istr(stack_a, stack_b, istr);
	return (0);
}
