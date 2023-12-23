/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:39:21 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/12/24 00:32:57 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// static int	z_cost(int z, int t)
// {
// 	if (z < 0)
// 		z = -z;
// 	if (t < 0)
// 		t = -t;
// 	return (z < t);
// }

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

t_stack	*ft_get_target(t_stack *stack, int len, int index)
{
	if (index < 0)
		return (stack + (len - 1));
	else if (index >= len)
		return (stack);
	while (stack && stack->z_index != index)
		stack = stack->next;
	return (stack);
}

int	ft_short(int nbr, int len)
{
	return (nbr - (nbr > len / 2) * len);
}

void	ft_rotate(t_stack *stack, int r)
{
	if (r < 0)
	{
		while (r++)
			rra(stack);
	}
	else
	{
		while (r--)
			ra(stack);
	}

}

int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

void	ft_push_b(t_stack **from, t_stack **to)
{
	*from = (*from)->next;
	(*from - 1)->next = NULL;
	if (*to)
	{
		(*from - 2)->next = (*from - 1);
		rotate_down(*to);
	}
	else
		*to = (*from - 1);
	write(1, "pb\n", 3);
}

void	ft_push_min_max(t_stack **a, t_stack **b, int len)
{
	int	min;
	int	max;

	min = ft_short(ft_get_target(*a, len, 0)->index, len);
	max = ft_short(ft_get_target(*a, len, len - 1)->index, len);
	if (ft_abs(min) < ft_abs(max))
	{
		ft_rotate(*a, min);
		ft_push_b(a, b);
		ft_rotate(*a, max - min);
		ft_push_b(a, b);
	}
	else
	{
		ft_rotate(*a, max);
		ft_push_b(a, b);
		ft_rotate(*a, min - max);
		ft_push_b(a, b);
	}
}

int	ft_get_smaller(t_stack *stack, int z)
{
	t_stack	*head;
	int		x;
	int		i;

	x = -1;
	i = 0;
	head = stack;
	while (stack)
	{
		if (stack->z_index > x && stack->z_index < z)
			x = stack->z_index;
		stack = stack->next;
	}
	if (x == INT_MAX)
	{
		while (head && head->z_index != 0 && i++ >= 0)
			head = head->next;
		return (i);
	}
	while (head && head->z_index != x && i++ >= 0)
		head = head->next;
	return (i);
}

void	ft_push_to_b(t_stack **a, t_stack **b, int len_a)
{
	int	cost;
	int	len_b;

	ft_push_min_max(a, b, len_a);
	len_a -= 2;
	len_b = 2;
	while (len_a > 3)
	{
		cost = ft_short(ft_get_smaller(*b, (*a)->z_index), len_b);
		ft_rotate(*b, cost);
		ft_push_b(a, b);
		len_a--;
		len_b++;
	}
}

void	ft_sort_three(t_stack *stack)
{
	if (stack->z_index < stack->next->z_index)
	{
		if (stack->next->z_index > stack->next->next->z_index)
			rra(stack);
	}
	else if (stack->z_index > stack->next->next->z_index)
		ra(stack);
	if (stack->z_index > stack->next->z_index)
		ft_swap(stack, stack->next);
}

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
	{
		while (head && head->z_index != 0 && i++ >= 0)
			head = head->next;
		return (i);
	}
	while (head && head->z_index != x && i++ >= 0)
		head = head->next;
	return (i);
}

void	ft_push_a(t_stack **a, t_stack **b, int len_b)
{
	if (!b)
		return ;
	ra(*b);
	(*b + len_b - 1)->next = *a;
	*a -= 1;
	if (*a == *b)
		*b = NULL;
	else
		(*b + len_b - 2)->next = NULL;
	write(1, "pa\n", 3);
}

void	ft_push_to_a(t_stack **a, t_stack **b, int len_b)
{
	int	cost;
	int	len_a;

	len_a = 3;
	while (len_b)
	{
		cost = ft_short(ft_get_larger(*a, (*b)->z_index), len_a);
		ft_rotate(*a, cost);
		ft_push_a(a, b, len_b);
		len_a++;
		len_b--;
	}
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
	ft_push_to_b(&stack_a, &stack_b, len);
	ft_sort_three(stack_a);
	ft_push_to_a(&stack_a, &stack_b, len - 3);
	int r = ft_short(ft_get_target(stack_a, len, 0)->index, len);
	ft_rotate(stack_a, r);
	// free(stack_a);
	return (0);
}
/*ARG=`ruby -e "puts (0..3).to_a.shuffle.join(' ')"`; ./a.out $ARG | wc -l*/