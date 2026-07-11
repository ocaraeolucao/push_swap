/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luvieira <luvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 18:27:06 by luvieira          #+#    #+#             */
/*   Updated: 2026/07/11 20:50:54 by luvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef enum e_strategy
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}	t_strategy;

typedef struct s_bench
{
	int		active;
	float	disorder;
	char	*strategy_name;
	char	*complexity;
	int		total_ops;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}	t_bench;

typedef struct s_stack
{
	int				number;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

int		main(int argc, char **argv);
int		stacksize(t_stack *stack);
int		set_options(t_bench *bench, t_strategy *strategy, int *argc,
			char ***argv);

t_stack	*new_node(char *split, t_stack *stack);
t_stack	*stacklast(t_stack *stack);
t_stack	*stacknew(int number);

void	stackadd_front(t_stack **stack, t_stack *new);
void	stackadd_back(t_stack **stack, t_stack *new);

void	master_sort(t_stack **stack_a, t_stack **stack_b, t_strategy strategy,
			t_bench *bench);
void	selection_sort(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
void	chunking_sort(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
void	radix_sort(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
void	sort_3(t_stack **stack, t_bench *bench);
void	printbench(t_bench bench);

void	push_a(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
void	push_b(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
void	reverse_rotate_a(t_stack **stack_a, t_bench *bench);
void	reverse_rotate_b(t_stack **stack_b, t_bench *bench);
void	reverse_rotate_r(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
void	rotate_a(t_stack **stack_a, t_bench *bench);
void	rotate_b(t_stack **stack_b, t_bench *bench);
void	rotate_r(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
void	swap_a(t_stack **stack_a, t_bench *bench);
void	swap_b(t_stack **stack_b, t_bench *bench);
void	swap_s(t_stack **stack_a, t_stack **stack_b, t_bench *bench);

#endif