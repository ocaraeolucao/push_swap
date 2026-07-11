/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 19:46:43 by marvin            #+#    #+#             */
/*   Updated: 2026/07/06 19:46:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	void_swap(t_stack **stack)
{
	t_stack	*first_stack;
	t_stack	*second_stack;
	t_stack	*third_stack;

	if (!*stack || !(*stack)->next)
		return ;
	first_stack = *stack;
	second_stack = (*stack)->next;
	third_stack = (*stack)->next->next;
	first_stack->prev = second_stack;
	first_stack->next = third_stack;
	if (third_stack != NULL)
		third_stack->prev = first_stack;
	second_stack->prev = NULL;
	second_stack->next = first_stack;
	*stack = second_stack;
}

void	swap_a(t_stack **stack_a, t_bench *bench)
{
	void_swap(stack_a);
	ft_putstr_fd("sa\n", 1);
	if (bench && bench->active)
	{
		bench->sa++;
		bench->total_ops++;
	}
}

void	swap_b(t_stack **stack_b, t_bench *bench)
{
	void_swap(stack_b);
	ft_putstr_fd("sb\n", 1);
	if (bench && bench->active)
	{
		bench->sb++;
		bench->total_ops++;
	}
}

void	swap_s(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	void_swap(stack_a);
	void_swap(stack_b);
	ft_putstr_fd("ss\n", 1);
	if (bench && bench->active)
	{
		bench->ss++;
		bench->total_ops += 2;
	}
}
