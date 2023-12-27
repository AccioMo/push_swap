/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeggaf <mzeggaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:35:47 by mzeggaf           #+#    #+#             */
/*   Updated: 2023/12/27 19:36:05 by mzeggaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# define BUFFER_SIZE 1

# include <stdlib.h>
# include <unistd.h>
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

/*			tools				*/
t_stack	*ft_create_t_stack(int *nbs, int len);
int		ft_stack_len(t_stack *stack);
int		ft_sorted(t_stack *stack);
int		ft_is_int_max(char *str);

/*			input			*/
t_stack	*ft_get_stack(int argc, char *argv[]);
void	ft_free(char **input);

/*			functions			*/
char	*ft_realloc(char *istr, char *buffer);
char	*ft_read(int fd, char *buffer);
int		ft_apply_instructions(t_stack *a, t_stack *b, char **istr);

/*			instructions			*/
void	swap(t_stack *a, t_stack *b);
void	swap_both(t_stack *a, t_stack *b);
void	push_a(t_stack **a, t_stack **b);
void	push_b(t_stack **a, t_stack **b);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	rotate_both(t_stack *a, t_stack *b);
void	reverse_rotate_both(t_stack *a, t_stack *b);

#endif
