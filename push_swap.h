/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:35:47 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/12/15 19:57:51 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

void	ra(int *nbrs, int len);
void	rra(int *nbrs, int len);
void	ft_swap(int *a, int *b);
int		ft_push(int *nbs, int len);

/*			from libft			*/
int		ft_atoi(char *str);
char	**ft_split(char *str, char c);

#endif
