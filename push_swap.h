/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:35:47 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/12/25 18:33:31 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libftprintf/ft_printf.h"
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
int		ft_getlen(char **array);
int		*ft_get_nbs(char **input, int len);
void	ft_free(char **input, int len);
int		ft_check_input(char **input, int len);
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
void	ft_rr(t_stack *a, t_stack *b);
void	ft_rrr(t_stack *a, t_stack *b);
void	ft_rotate(t_stack *stack, int r, char s);
void	ft_full_rotate(t_stack *a, t_stack *b, int costa, int costb);

/*			targets			*/
int		ft_get_larger(t_stack *stack, int z);
int		ft_get_smaller(t_stack *stack, int z);
int		ft_get_target(t_stack *stack, int index);
void	ft_sort_three(t_stack *stack);

/*			stack_a			*/
void	ft_get_costs(t_stack *a, t_stack *b, int len_a, int len_b);
t_stack	*ft_barter(t_stack *stack);
void	ft_push_a(t_stack **a, t_stack **b, int len_b);
void	ft_push_to_a(t_stack **a, t_stack **b);

/*			stack_b			*/
int		ft_get_first_small(t_stack *stack, int len, int z);
void	ft_push_b(t_stack **a, t_stack **b);
void	ft_push_to_b(t_stack **a, t_stack **b);

#endif
