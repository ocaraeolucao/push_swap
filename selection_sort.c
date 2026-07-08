/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luvieira <luvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 18:13:57 by luvieira          #+#    #+#             */
/*   Updated: 2026/07/08 19:23:46 by luvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*get_min_node(t_stack *stack)
{
	t_stack	*min_node;

	if (!stack)
		return (NULL);
	min_node = stack;
	while (stack->next != NULL)
	{
		if (stack->next->number < min_node->number)
			min_node = stack->next;
		stack = stack->next;
	}
	return (min_node);
}

static int	get_node_position(t_stack *stack, t_stack *min_node)
{
	int	i;

	i = 0;
	if (!stack || !min_node)
		return (i);
	while (stack)
	{
		if (stack == min_node)
			break ;
		i++;
		stack = stack->next;
	}
	return (i);
}

void	selection_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*min_node;
	int		node_position;
	int		size;

	size = stacksize(*stack_a);
	while (size > 3)
	{
		min_node = get_min_node(*stack_a);
		node_position = get_node_position(*stack_a, min_node);
		while (*stack_a != min_node)
		{
			if (node_position <= size / 2)
				rotate_a(stack_a);
			else
				reverse_rotate_a(stack_a);
		}
		push_b(stack_a, stack_b);
		size--;
	}
	if (size == 3)
		sort_3(stack_a);
	else if (size == 2)
		sort_2(stack_a);
	while (*stack_b != NULL)
		push_a(stack_a, stack_b);
}
