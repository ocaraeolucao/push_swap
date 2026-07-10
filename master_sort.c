/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 18:53:32 by marvin            #+#    #+#             */
/*   Updated: 2026/07/09 18:53:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static float	compute_disorder(t_stack *stack)
{
    t_stack	*current_node;
    t_stack	*compare_node;
    float   mistakes;
    float   total_pairs;

    if (!stack || !stack->next)
        return (0.0);
    mistakes = 0.0;
    total_pairs = 0.0;
    current_node = stack;
    while (current_node != NULL)
    {
        compare_node = current_node->next;
        while (compare_node != NULL)
        {
            total_pairs += 1.0;
            if (current_node->index > compare_node->index)
                mistakes += 1.0;
                
            compare_node = compare_node->next;
        }
        current_node = current_node->next;
    }
    return (mistakes / total_pairs);
}

static void	set_index(t_stack **stack, int size)
{
	t_stack	*current_node;
	t_stack	*min_node;
	int		current_index;

	current_index = 0;
	while (current_index < size)
	{
		current_node = *stack;
		min_node = NULL;
		while (current_node != NULL)
		{
			if (current_node->index == -1)
			{
				if (min_node == NULL || current_node->number < min_node->number)
					min_node = current_node;
			}
			current_node = current_node->next;
		}
		if (min_node != NULL)
			min_node->index = current_index;
		current_index++;
	}
}

static void	sort_2(t_stack **stack, t_bench *bench)
{
	if ((*stack)->index > (*stack)->next->index)
		swap_a(stack, bench);
}

void	sort_3(t_stack **stack, t_bench *bench)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack *third_node;

	first_node = *stack;
	second_node = first_node->next;
	third_node = second_node->next;
    if (first_node->index < second_node->index && second_node->index < third_node->index)
        return ;
	else if (first_node->index < second_node->index)
		reverse_rotate_a(stack, bench);
	else if (first_node->index > third_node->index)
		rotate_a(stack, bench);
	sort_2(stack, bench);
}

void    master_sort(t_stack **stack_a, t_stack **stack_b, t_strategy strategy, t_bench *bench)
{
    int     size;
    float   disorder;
    
    size = stacksize(*stack_a);
    set_index(stack_a, size);
    if (size == 2 && strategy == ADAPTIVE)
    {
        sort_2(stack_a, bench);
        return ;
    }
    else if (size == 3 && strategy == ADAPTIVE)
    {
        sort_3(stack_a, bench);
        return ;
    }
    disorder = compute_disorder(*stack_a);
    bench->disorder = disorder * 100.0;
    if (disorder == 0.0)
        return ;
    else if (strategy == SIMPLE || (disorder < 0.2 && strategy == ADAPTIVE))
        selection_sort(stack_a, stack_b, bench);
    else if (strategy == MEDIUM || (disorder < 0.5 && strategy == ADAPTIVE))
        chunking_sort(stack_a, stack_b, bench);
    else
        radix_sort(stack_a, stack_b, bench);
}