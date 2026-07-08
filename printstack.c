/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 20:34:23 by marvin            #+#    #+#             */
/*   Updated: 2026/07/06 20:34:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printstack(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_a || *stack_b)
	{
		if (*stack_a)
			ft_printf("%d", (*stack_a)->number);
		ft_printf("  ");
		if (*stack_b)
			ft_printf("%d", (*stack_b)->number);
		ft_printf("\n");
		if (*stack_a)
			*stack_a = (*stack_a)->next;
		if (*stack_b)
			*stack_b = (*stack_b)->next;
	}
}

void	sort_2(t_stack **stack)
{
	if ((*stack)->number > (*stack)->next->number)
		swap_a(stack);
}

void	sort_3(t_stack **stack)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack *third_node;

	first_node = *stack;
	second_node = first_node->next;
	third_node = second_node->next;
	if (first_node->number < second_node->number)
		reverse_rotate_a(stack);
	else if (first_node->number > third_node->number)
		rotate_a(stack);
	sort_2(stack);
}