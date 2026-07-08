/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luvieira <luvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 18:53:26 by luvieira          #+#    #+#             */
/*   Updated: 2026/07/08 19:59:41 by luvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stacksize(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

t_stack	*stacklast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	stackadd_front(t_stack **stack, t_stack *new)
{
	if (!new)
		return ;
	new->next = *stack;
	if (new->next)
		new->next->prev = new;
	*stack = new;
}

void	stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!stack || !new)
		return ;
	if (*stack == NULL)
		*stack = new;
	else
	{
		last = stacklast(*stack);
		new->prev = last;
		last->next = new;
	}	
}

t_stack	*stacknew(int number)
{
	t_stack	*stacknew;

	stacknew = (t_stack *)malloc(sizeof(t_stack));
	if (!stacknew)
		return (NULL);
	stacknew->number = number;
	stacknew->prev = NULL;
	stacknew->next = NULL;
	stacknew->index = -1;
	return (stacknew);
}
