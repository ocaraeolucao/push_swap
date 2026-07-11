/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 16:56:24 by marvin            #+#    #+#             */
/*   Updated: 2026/07/09 16:56:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int max_index)
{
	int	max_bits;

	max_bits = 0;
	while (max_index > 0)
	{
		max_index = max_index >> 1;
		max_bits++;
	}
	return (max_bits);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	size = stacksize(*stack_a);
	bench->complexity = "O(n log n)";
	max_bits = get_max_bits(size - 1);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 0)
				push_b(stack_a, stack_b, bench);
			else
				rotate_a(stack_a, bench);
			j++;
		}
		while (*stack_b != NULL)
			push_a(stack_a, stack_b, bench);
		i++;
	}
}
