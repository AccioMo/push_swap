/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:35:47 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/12/19 17:22:04 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "ftprintf/ft_printf.h"
# include "libft/libft.h"

/*			structs			*/
typedef struct s_stack
{
	int				nb;
	int				index;
	int				z_index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/*			functions			*/
void	ra(t_stack *nbrs);
void	rra(t_stack *nbrs);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	ft_swap(t_stack *a, t_stack *b);
int		ft_push(t_stack *nbs);
int		ft_sorted(t_stack *stack);
t_stack	*ft_create_t_stack(int *nbs, int len);
void	rotate_up(t_stack *stack);
void	rotate_down(t_stack *stack);

#endif
