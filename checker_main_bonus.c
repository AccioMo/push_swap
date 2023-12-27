/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 01:39:58 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/12/27 19:45:51 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ft_check_double_c(char *str, char c)
{
	while (*str)
	{
		if (*str == c && *(str + 1) == c)
			return (1);
		str++;
	}
	if (*(str - 1) != '\n')
		return (1);
	return (0);
}

static char	**ft_get_instructions(void)
{
	char	*buffer;
	char	**istr;
	char	*tmp;

	tmp = NULL;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	buffer[BUFFER_SIZE] = '\0';
	while (buffer)
	{
		buffer = ft_read(0, buffer);
		tmp = ft_realloc(tmp, buffer);
		if (!tmp)
			return (free(buffer), NULL);
	}
	if (ft_check_double_c(tmp, '\n'))
		return (free(buffer), write(2, "Error\n", 6), NULL);
	istr = ft_split(tmp, '\n');
	return (free(tmp), istr);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**istr;

	stack_b = NULL;
	stack_a = ft_get_stack(argc, argv);
	istr = ft_get_instructions();
	if (!istr)
		return (free(stack_a), 1);
	ft_apply_instructions(stack_a, stack_b, istr);
	ft_free(istr);
	return (0);
}
