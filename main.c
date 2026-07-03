/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luvieira <luvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 18:21:53 by luvieira          #+#    #+#             */
/*   Updated: 2026/06/30 20:46:31 by luvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **split)
{
	int		i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	printerror(t_stack **stack, char **split)
{
	t_stack	*next;

	ft_putstr_fd("Error\n", 2);
	free_split(split);
	while (*stack)
	{
		next = stack[0]->next;
		free(stack[0]);
		stack[0] = next;
	}
	return (0);
}

static void	printstack(t_stack **stack)
{
	t_stack	*node;

	node = *stack;
	while (node)
	{
		ft_printf("%d\n", node->number);
		node = node->next;
	}
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

int	main(int argc, char **argv)
{
	t_stack	*stack;
	char	**split;
	long	atol;
	int		i;
	int		j;

	if (argc < 2)
		return (0);
	i = 1;
	stack = NULL;
	while (argv[i])
	{
		j = 0;
		split = ft_split(argv[i], ' ');
		while (split[j])
		{
			if (!is_number(split[j]))
				return (printerror(&stack, split));
			atol = ft_atol(split[j]);
			if (atol > 2147483647 || atol < -2147483648 || stackis_duplicated(stack, (int)atol))
				return (printerror(&stack, split));
			stackadd_back(&stack, stacknew((int)atol));
			j++;
		}
		free_split(split);
		i++;
	}
	printstack(&stack);
	return (0);
}
