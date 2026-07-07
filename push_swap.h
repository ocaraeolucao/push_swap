/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luvieira <luvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 18:27:06 by luvieira          #+#    #+#             */
/*   Updated: 2026/06/30 20:35:30 by luvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"


typedef struct s_stack
{
	int				number;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

int		main(int argc, char **argv);

int		is_duplicated(t_stack *stack, int number);
int		is_number(const char *number);
int 	is_sorted(t_stack *stack);

t_stack	*stacklast(t_stack *stack);
t_stack	*stacknew(int number);

void	stackadd_front(t_stack **stack, t_stack *new);
void	stackadd_back(t_stack **stack, t_stack *new);
void	stackclear(t_list **stack);

void	printstack(t_stack **stack_a, t_stack **stack_b);
void    push_a(t_stack **stack_a, t_stack **stack_b);
void    push_b(t_stack **stack_a, t_stack **stack_b);
void    reverse_rotate_a(t_stack **stack_a);
void    reverse_rotate_b(t_stack **stack_b);
void    reverse_rotate_r(t_stack **stack_a, t_stack **stack_b);
void    rotate_a(t_stack **stack_a);
void    rotate_b(t_stack **stack_b);
void    rotate_r(t_stack **stack_a, t_stack **stack_b);
void    swap_a(t_stack **stack_a);
void    swap_b(t_stack **stack_b);
void    swap_s(t_stack **stack_a, t_stack **stack_b);

#endif