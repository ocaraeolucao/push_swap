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
	swap_a(stack_a);    
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