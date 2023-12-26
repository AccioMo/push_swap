/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 01:39:58 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/12/26 03:51:47 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_strncpy(char *dest, char *src, int n)
{
	while (n > 0 && *src)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	*dest = '\0';
	return (dest);
}

char	*ft_fstrjoin(char *istr, char *buffer)
{
	char	*str;
	int	l_istr;
	int	l_buffer;

	if (buffer == NULL)
		return (istr);
	l_istr = ft_strlen(istr);
	l_buffer = ft_strlen(buffer);
	str = (char *)malloc(sizeof(char) * (l_istr + l_buffer + 1));
	if (!str)
		return (free(istr), NULL);
	ft_strncpy(ft_strncpy(str, istr, l_istr), buffer, l_buffer);
	if (istr)
		free(istr);
	return (str);
}
char	*ft_read(int fd, char *buffer)
{
	int	rd;

	rd = read(fd, buffer, BUFFER_SIZE);
	if (rd == 0)
	{
		free(buffer);
		return (NULL);
	}
	*(buffer + rd) = '\0';
	return (buffer);
}

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

int	ft_status_code(t_stack **a, t_stack **b, char *istr)
{
	if (!ft_strncmp(istr, "sa", -1))
		return (swap(*a, (*a)->next));
	else if (!ft_strncmp(istr, "sb", -1))
		return (swap(*b, (*b)->next));
	else if (!ft_strncmp(istr, "ss", -1))
		return (swap_both(*a, (*b)));
	else if (!ft_strncmp(istr, "ra", -1))
		return (rotate(*a));
	else if (!ft_strncmp(istr, "rb", -1))
		return (rotate(*b));
	else if (!ft_strncmp(istr, "rra", -1))
		return (reverse_rotate(*a));
	else if (!ft_strncmp(istr, "rrb", -1))
		return (reverse_rotate(*b));
	else if (!ft_strncmp(istr, "rr", -1))
		return (rotate_both(*a, (*b)));
	else if (!ft_strncmp(istr, "rrr", -1))
		return (reverse_rotate_both(*a, (*b)));
	else if (!ft_strncmp(istr, "pa", -1))
		return (push_a(a, b));
	else if (!ft_strncmp(istr, "pb", -1))
		return (push_b(a, b));
	else
		return (1);
}

void	ft_apply_istr(t_stack *a, t_stack *b, char **istr)
{
	t_stack	*anchor;

	anchor = a;
	while (*istr)
	{
		if (ft_status_code(&a, &b, *istr) == 1)
			return (free(anchor), write(2, "Error\n", 6), exit(1));
		istr++;
	}
	if (ft_sorted(a) && b == NULL)
		return (free(anchor), write(1, "OK\n", 3), exit(0));
	else
		return (free(anchor), write(1, "KO\n", 3), exit(0));
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
