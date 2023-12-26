/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 17:23:56 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/12/26 01:34:49 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_getlen(char **array)
{
	int	len;

	len = 0;
	while (*(array + len))
		len++;
	return (len);
}

int	*ft_get_nbs(char **input, int len)
{
	int		*nbs;

	if (ft_check_input(input, len))
		return (write(2, "Error\n", 6), NULL);
	nbs = (int *)malloc(len * sizeof(int));
	if (!nbs)
		return (NULL);
	while (len--)
		*(nbs + len) = ft_atoi(*(input + len));
	return (nbs);
}

void	ft_free(char **input)
{
	int	i;

	i = 0;
	while (*(input + i))
	{
		free(*(input + i));
		i++;
	}
	free(input);
}

int	ft_check_input(char **input, int len)
{
	char	*str;
	int		i;

	while (*input)
	{
		i = 1;
		str = *input;
		if (ft_is_int_max(str) == 0)
			return (1);
		while (*(input + i))
		{
			if (ft_strncmp(str, *(input + i), -1) == 0)
				return (1);
			i++;
		}
		while (*str)
		{
			if (*str != '-' && !ft_isdigit(*str))
				return (1);
			str++;
		}
		input++;
	}
	input -= len;
	return (0);
}

t_stack	*ft_get_stack(int argc, char *argv[])
{
	char	**input;
	int		*nbs;
	int		len;

	if (argc <= 1)
		exit(0);
	else if (argc == 2)
	{
		input = ft_split(*(argv + 1), ' ');
		len = ft_getlen(input);
		nbs = ft_get_nbs(input, len);
		ft_free(input);
	}
	else
	{
		len = argc - 1;
		nbs = ft_get_nbs(argv + 1, len);
	}
	if (!nbs)
		exit(1);
	return (ft_create_t_stack(nbs, len));
}
