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

static int	is_duplicated(t_stack *stack, int number)
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

static int	is_number(const char *number)
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

t_stack	*newnode(char *split, t_stack *stack)
{
	long	atol;
	t_stack	*new;

	if (!is_number(split))
		return (NULL);
	atol = ft_atol(split);
	if (atol > 2147483647 || atol < -2147483648 || is_duplicated(stack,
			(int)atol))
		return (NULL);
	new = stacknew((int)atol);
	return (new);
}
