/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:39:21 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/12/21 16:05:52 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack *stack)
{
	ft_printf("___________\n");
	while (stack)
	{
		ft_printf("| %d: i: %d |\n", stack->nb, stack->z_index);
		stack = stack->next;
	}
	ft_printf("___________\n");
}

int	ft_getsm(t_stack *stack)
{
	t_stack	*sm;

	sm = stack;
	while (stack)
	{
		if (sm->nb > stack->nb)
			sm = stack;
		stack = stack->next;
	}
	return (sm->index);
}

int	ft_getlen(char **array)
{
	int	len;

	len = 0;
	while (*(array + len))
		len++;
	return (len);
}

void	ft_free(char **input, int len)
{
	while (*input)
	{
		free(*input);
		input++;
	}
	free(input - len);
}

int	*ft_get_nbs(char **input, int len)
{
	int		*nbs;

	nbs = (int *)malloc(len * sizeof(int));
	if (!nbs)
		return (NULL);
	while (len--)
		*(nbs + len) = ft_atoi(*(input + len));
	return (nbs);
}

int	ft_get_diff(t_stack *current, t_stack *target)
{
	if (current->index > target->index)
		return (current->index - target->index);
	else
		return (target->index - current->index);
}

// static void	ft_repeat(int n, void (*f)(t_stack *), t_stack *arg)
// {
// 	while (n-- > 0)
// 		f(arg);
// }

static int	z_cost(int z, int t)
{
	if (z < 0)
		z = -z;
	if (t < 0)
		t = -t;
	return (z < t);
}

void	ft_push_swap(t_stack *stack, int len)
{
	int	r = 10;
	
	while (r--)
	{
		ft_get_costs(stack, len);
		if (stack->next->z_index == stack->z_index - 1 || stack->next->z_index == len - 1)
			ra(stack);
		else if (stack->next->z_index == stack->z_index + 1)
			ft_swap(stack, stack->next);
		else if (z_cost(stack->z_cost, stack->t_cost))
		{
			ft_printf("z\n");
			if (stack->z_cost > 0)
				rra(stack);
			else
			{
				ft_swap(stack, stack->next);
				ra(stack);
			}
		}
		else
		{
			ft_printf("t\n");
			if (stack->t_cost > 0)
			{
				ft_swap(stack, stack->next);
				ra(stack);
			}
			else
				rra(stack);
		}
		ft_print_stack(stack);
	}
}

int	ft_check_input(char **input, int len)
{
	int	valid;

	valid = 1;
	if (len > 0)
		valid = ft_check_input((input + 1), len - 1);
	while ((**input >= '0' && **input <= '9') || **input == ' ')
		(*input)++;
	if (**input == '\0')
		return (valid);
	return (0);
}

int	ft_getpnm(int *nbs, int len, int pivot)
{
	int	i;

	i = 0;
	while (i <= len--)
	{
		if (*(nbs + i) < pivot)
			return (i);
		else if (*(nbs + len) < pivot)
			return (len);
		i++;
	}
	return (-1);
}

int	main(int argc, char *argv[])
{
	char	**input;
	int		*nbs;
	int		len;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 1)
		return (0);
	else if (argc == 2)
	{
		input = ft_split(*(argv + 1), ' ');
		len = ft_getlen(input);
		nbs = ft_get_nbs(input, len);
		ft_free(input, len);
	}
	else
	{
		len = argc - 1;
		nbs = ft_get_nbs(argv + 1, len);
	}
	stack_a = ft_create_t_stack(nbs, len);
	stack_b = NULL;
	// while (chunks--)
	// {
	// 	chunk = ft_fill_chunk(stack_a, chunk_size, len);
	// 	ft_arrange_b(stack_b, chunk);
	// }
	// ft_arrange_a(stack_a, stack_b, len);
	// ft_printf("%d\n",ft_get_target(stack_a, len)->nb);
	ft_push_swap(stack_a, len);
	ft_print_stack(stack_a);
	ft_print_stack(stack_b);
	// ra(stack_a);
	// ft_swap(stack_a, stack_a->next);
	// ft_print_stack(stack_a);
	// rra(stack_a);
	// ft_printf("\n");
	// ft_print_stack(stack_a);
	// ra(stack_a);
	// ft_printf("\n");
	// ft_print_stack(stack_a);
	// free(stack_a);
	return (0);
}
/*ARG=`ruby -e "puts (0..3).to_a.shuffle.join(' ')"`; ./a.out $ARG | wc -l*/