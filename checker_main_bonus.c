/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 01:39:58 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/12/26 05:14:07 by mzeggaf          ###   ########.fr       */
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
	stack_b = NULL;
	stack_a = ft_get_stack(argc, argv);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	buffer[BUFFER_SIZE] = '\0';
	while (buffer)
	{
		buffer = ft_read(0, buffer);
		tmp = ft_fstrjoin(tmp, buffer);
	}
	free(buffer);
	istr = ft_split(tmp, '\n');
	ft_apply_istr(stack_a, stack_b, istr);
	ft_free(istr);
	return (0);
}
