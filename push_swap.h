/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:35:47 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/12/27 19:30:36 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

/*			structs			*/
typedef struct s_stack
{
	int				nb;
	int				index;
	int				z_index;
	int				costa;
	int				costb;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_create_t_stack(int *nbs, int len);
int		ft_stack_len(t_stack *stack);

/*			input			*/
t_stack	*ft_get_stack(int argc, char *argv[]);

/*			tools			*/
int		ft_abs(int nbr);
int		ft_short(int nbr, int len);
void	swap(t_stack *a, t_stack *b);
void	rotate_up(t_stack *stack);
void	rotate_down(t_stack *stack);

/*			general_utils			*/
int		ft_sorted(t_stack *stack);
void	ft_sa(t_stack *a, t_stack *b);
void	ft_sb(t_stack *a, t_stack *b);
void	ft_rx(t_stack *stack, char s);
void	ft_rrx(t_stack *stack, char s);

/*			rotations			*/
void	ft_rotate(t_stack *stack, int r, char s);
void	ft_full_rotate(t_stack *a, t_stack *b, int costa, int costb);

/*			targets			*/
int		ft_get_larger(t_stack *stack, int z);
int		ft_get_target(t_stack *stack, int index);
void	ft_sort_three(t_stack *stack);
int		ft_is_int_max(char *str);

/*			stack_a			*/
void	ft_push_to_a(t_stack **a, t_stack **b);

/*			stack_b			*/
void	ft_push_to_b(t_stack **a, t_stack **b);

#endif
