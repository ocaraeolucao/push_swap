/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 00:01:59 by marvin            #+#    #+#             */
/*   Updated: 2026/07/07 00:01:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	void_reverse_rotate(t_stack **stack)
{
	t_stack	*first_stack;
	t_stack	*last_stack;

	if (!*stack || !(*stack)->next)
		return ;
	first_stack = *stack;
	last_stack = stacklast(first_stack);
	last_stack->prev->next = NULL;
	*stack = last_stack;
	(*stack)->prev = NULL;
	(*stack)->next = first_stack;
	first_stack->prev = *stack;
}

void	reverse_rotate_a(t_stack **stack_a, t_bench *bench)
{
	void_reverse_rotate(stack_a);
	ft_putstr_fd("rra\n", 1);
	if (bench && bench->active)
	{
		bench->rra++;
		bench->total_ops++;
	}
}

void	reverse_rotate_b(t_stack **stack_b, t_bench *bench)
{
	void_reverse_rotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
	if (bench && bench->active)
	{
		bench->rrb++;
		bench->total_ops++;
	}
}

void	reverse_rotate_r(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	void_reverse_rotate(stack_a);
	void_reverse_rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
	if (bench && bench->active)
	{
		bench->rrr++;
		bench->total_ops++;
	}
}
