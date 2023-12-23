/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:35:47 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/12/23 23:37:38 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "ftprintf/ft_printf.h"
# include "libft/libft.h"

/*			structs			*/
typedef struct s_stack
{
	int				nb;
	int				index;
	int				z_index;
	int				z_cost;
	int				t_cost;
	struct s_stack	*target;
	struct s_stack	*next;
}	t_stack;

/*			functions			*/
void	ra(t_stack *nbrs);
void	rra(t_stack *nbrs);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	ft_swap(t_stack *a, t_stack *b);
void	ft_push(t_stack **from, t_stack **to);
int		ft_sorted(t_stack *stack);
t_stack	*ft_create_t_stack(int *nbs, int len);
void	ft_get_costs(t_stack *stack, int len);
void	rotate_up(t_stack *stack);
void	rotate_down(t_stack *stack);

#endif
