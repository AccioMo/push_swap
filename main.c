/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:39:21 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/12/24 17:00:07 by mzeggaf          ###   ########.fr       */
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

int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

void	ft_push_b(t_stack **a, t_stack **b)
{
	*a = (*a)->next;
	(*a - 1)->next = NULL;
	if (*b)
	{
		(*a - 2)->next = (*a - 1);
		rotate_down(*b);
	}
	else
		*b = (*a - 1);
	write(1, "pb\n", 3);
}

int	ft_get_first_small(t_stack *stack, int len, int z)
{
	t_stack	*head;
	int		x;
	int		i;

	x = -1;
	i = 0;
	head = stack;
	while (stack)
	{
		if (x == -1 && stack->z_index < z)
			x = i;
		else if ((len - i) > 0 && len - i < x && stack->z_index < z)
			x = i;
		stack = stack->next;
		i++;
	}
	if (x == -1)
		return (z);
	// while (head && head->z_index != x && i++ >= 0)
	// 	head = head->next;
	return (x);
}

void	ft_push_to_b(t_stack **a, t_stack **b, int len_a)
{
	int	cost;
	int	len_b;
	int	pivot;
	int	chunk_size;

	// ft_push_min_max(a, b, len_a);
	// len_a -= 2;
	len_b = 0;
	chunk_size = len_a / 2;
	pivot = chunk_size;
	while (len_a > 3)
	{
		if (*b && (*b)->next && (*b)->z_index + 1 == (*b)->next->z_index)
			ft_sb(*b, (*b)->next);
		// if (*a && (*a)->next && (*a)->z_index == (*a)->next->z_index + 1)
		// 	ft_sa(*a, (*a)->next);
		cost = ft_get_first_small(*a, len_a, pivot);
		if (cost == pivot)
			pivot += chunk_size;
		cost = ft_short(cost, len_a);
		ft_rotate(*a, cost, 'a');
		ft_push_b(a, b);
		// ft_print_stack(*a);
		// ft_print_stack(*b);
		len_a--;
		len_b++;
	}
		// ft_print_stack(*a);
		// ft_print_stack(*b);
}

void	ft_sort_three(t_stack *stack)
{
	if (stack->z_index < stack->next->z_index)
	{
		if (stack->next->z_index > stack->next->next->z_index)
			ft_rrx(stack, 'a');
	}
	else if (stack->z_index > stack->next->next->z_index)
		ft_rx(stack, 'a');
	if (stack->z_index > stack->next->z_index)
		ft_sa(stack, stack->next);
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
		return (ft_get_larger(head, -1));
	while (head && head->z_index != x && i++ >= 0)
		head = head->next;
	return (i);
}

void	ft_push_a(t_stack **a, t_stack **b, int len_b)
{
	if (!b)
		return ;
	rotate_up(*b);
	(*b + len_b - 1)->next = *a;
	*a -= 1;
	if (*a == *b)
		*b = NULL;
	else
		(*b + len_b - 2)->next = NULL;
	write(1, "pa\n", 3);
}

int	ft_get_smaller(t_stack *stack, int z)
{
	t_stack	*head;
	int		x;
	int		i;

	i = 0;
	x = -1;
	head = stack;
	while (stack)
	{
		if (stack->z_index > x && stack->z_index < z)
			x = stack->z_index;
		stack = stack->next;
	}
	if (x == -1)
		return (ft_get_smaller(head, INT_MAX));
	while (head && head->z_index != x && i++ >= 0)
		head = head->next;
	return (i);
}

void	ft_get_costs(t_stack *a, t_stack *b, int len_a, int len_b)
{
	int	i;

	i = 0;
	while (b)
	{
		b->costb = ft_short(i, len_b);
		b->costa = ft_short(ft_get_larger(a, (b)->z_index), len_a);
		b = b->next;
		i++;
	}
}

void	ft_rr(t_stack *a, t_stack *b)
{
	rotate_up(a);
	rotate_up(b);
	write(1, "rr\n", 3);
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	rotate_down(a);
	rotate_down(b);
	write(1, "rrr\n", 4);
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

t_stack	*ft_barter(t_stack *stack)
{
	t_stack	*best;
	int		to_best;
	int		to_stack;

	best = stack;
	while (stack)
	{
		to_best = ft_abs(best->costa) + ft_abs(best->costb);
		to_stack = ft_abs(stack->costa) + ft_abs(stack->costb);
		if (to_stack < to_best)
			best = stack;
		stack = stack->next;
	}
	return (best);
}

void	ft_push_to_a(t_stack **a, t_stack **b, int len_b)
{
	t_stack	*best;
	int		len_a;

	len_a = 3;
	while (len_b)
	{
		ft_get_costs(*a, *b, len_a, len_b);
		// ft_printf("ca: %d\ncb: %d\n", (*b)->costa, (*b)->costb);
		// ft_print_stack(*a);
		// ft_print_stack(*b);
		best = ft_barter(*b);
		ft_full_rotate(*a, *b, best->costa, best->costb);
		// if (ft_abs(costa) < ft_abs(costb))
			// ft_rotate(*a, costa, 'a');
		// else
		// 	ft_rotate(*b, costb, 'b');
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
	ft_rotate(stack_a, r, 'a');
	// ft_print_stack(stack_a);
	// ft_print_stack(stack_b);
	// free(stack_a);
	return (0);
}
/*ARG=`ruby -e "puts (0..3).to_a.shuffle.join(' ')"`; ./a.out $ARG | wc -l*/