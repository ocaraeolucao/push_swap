/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luvieira <luvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 02:48:57 by marvin            #+#    #+#             */
/*   Updated: 2026/07/08 20:43:20 by luvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicated(t_stack *stack, int number)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->number == number)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	is_number(const char *number)
{
	int	i;

	i = 0;
	if (number[i] == '+' || number[i] == '-')
		i++;
	if (number[i] == '\0')
		return (0);
	while (number[i] != '\0')
	{
		if (!ft_isdigit(number[i]))
			return (0);
		i++;
	}
	return (1);
}

float	compute_disorder(t_stack *stack)
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
            if (current_node->number > compare_node->number)
                mistakes += 1.0;
                
            compare_node = compare_node->next;
        }
        current_node = current_node->next;
    }
    return (mistakes / total_pairs);
}

void	set_index(t_stack **stack)
{
	t_stack	*current_node;
	t_stack	*min_node;
	int		size;
	int		current_index;

	current_index = 0;
	size = stacksize(*stack);
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
