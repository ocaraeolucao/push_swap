/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunking_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luvieira <luvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 20:04:46 by luvieira          #+#    #+#             */
/*   Updated: 2026/07/08 20:42:58 by luvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_node_position(t_stack *stack, int max_index)
{
	int	i;

	i = 0;
	if (!stack)
		return (i);
	while (stack)
	{
		if (stack->index == max_index)
			break ;
		i++;
		stack = stack->next;
	}
	return (i);
}

static void chunk_stack(t_stack **stack_a, t_stack **stack_b, t_bench *bench, int size_a)
{
    int chunk;
    int limit;
    int count;

    chunk = ft_sqrt(size_a);
    limit = chunk;
    count = 0;
    while (*stack_a != NULL)
    {
        if ((*stack_a)->index < limit)
        {
            push_b(stack_a, stack_b, bench);
            count++;
            size_a--;
            if (count == limit)
                limit += chunk;
        }
        else
            rotate_a(stack_a, bench);
    }
}

static void get_max_top(t_stack **stack_a, t_stack **stack_b, t_bench *bench, int index)
{
    int node_position;
    int size_b;

    node_position = get_node_position(*stack_b, index);
    size_b = stacksize(*stack_b);
    while ((*stack_b)->index != index)
    {
        if ((*stack_b)->index == index - 1)
        {
            push_a(stack_a, stack_b, bench);
            node_position = get_node_position(*stack_b, index);
            size_b--;
            continue ;
        }
        if (node_position <= size_b / 2)
            rotate_b(stack_b, bench);
        else
            reverse_rotate_b(stack_b, bench);
    }
}

void	chunking_sort(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	int     size_a;
 
    size_a = stacksize(*stack_a);
    chunk_stack(stack_a, stack_b, bench, size_a);
    while (*stack_b != NULL)
    {
        get_max_top(stack_a, stack_b, bench, size_a - 1);
        push_a(stack_a, stack_b, bench);
        if ((*stack_a)->next && (*stack_a)->index > (*stack_a)->next->index)
        {
            swap_a(stack_a, bench);
            size_a--;
        }
        size_a--;
    }
}
