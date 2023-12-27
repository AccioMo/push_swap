/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_functions_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 04:05:37 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/12/27 19:32:07 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static char	*ft_strncpy(char *dest, char *src, int n)
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

char	*ft_realloc(char *istr, char *buffer)
{
	char	*str;
	int		l_istr;
	int		l_buffer;

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

static int	ft_status_code(t_stack **a, t_stack **b, char *istr)
{
	if (!ft_strncmp(istr, "sa", -1))
		swap(*a, (*a)->next);
	else if (!ft_strncmp(istr, "sb", -1))
		swap(*b, (*b)->next);
	else if (!ft_strncmp(istr, "ss", -1))
		swap_both(*a, (*b));
	else if (!ft_strncmp(istr, "ra", -1))
		rotate(*a);
	else if (!ft_strncmp(istr, "rb", -1))
		rotate(*b);
	else if (!ft_strncmp(istr, "rra", -1))
		reverse_rotate(*a);
	else if (!ft_strncmp(istr, "rrb", -1))
		reverse_rotate(*b);
	else if (!ft_strncmp(istr, "rr", -1))
		rotate_both(*a, (*b));
	else if (!ft_strncmp(istr, "rrr", -1))
		reverse_rotate_both(*a, (*b));
	else if (!ft_strncmp(istr, "pa", -1))
		push_a(a, b);
	else if (!ft_strncmp(istr, "pb", -1))
		push_b(a, b);
	else
		return (1);
	return (0);
}

int	ft_apply_instructions(t_stack *a, t_stack *b, char **istr)
{
	t_stack	*anchor;

	anchor = a;
	while (*istr)
	{
		if (ft_status_code(&a, &b, *istr) == 1)
			return (free(anchor), write(2, "Error\n", 6));
		istr++;
	}
	if (ft_sorted(a) && b == NULL)
		return (free(anchor), write(1, "OK\n", 3));
	else
		return (free(anchor), write(1, "KO\n", 3));
}
