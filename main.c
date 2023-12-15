/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:39:21 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/12/15 19:59:39 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_getsm(int *array, int len)
{
	int	i;
	int	sm;

	i = 0;
	sm = 0;
	while (i < len)
	{
		if (array[sm] > array[i])
			sm = i;
		i++;
	}
	return (sm);
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

void	ft_push_swap(int *nbs, int len)
{
	int	sm;
	int	sa;

	sa = len;
	while (len)
	{
		sm = ft_getsm(nbs, len);
		if (sm == 0)
		{
			if (!ft_push(nbs, len))
				break ;
			nbs++;
			len--;
		}
		else if (sm == 1)
			ft_swap(nbs, nbs + 1);
		else if (sm < len / 2)
			ra(nbs, len);
		else
			rra(nbs, len);
	}
	sa -= len;
	while (sa--)
		write(1, "pa\n", 3);
}

int	main(int argc, char *argv[])
{
	char	**input;
	int		*nbs;
	int		len;

	if (argc <= 1)
		return (0);
	if (argc == 2)
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
	ft_push_swap(nbs, len);
	// int		i;
	// i = 0;
	// while (i < len)
	// {
	// 	printf("%d ", nbs[i]);
	// 	i++;
	// }
	free(nbs);
	return (0);
}
