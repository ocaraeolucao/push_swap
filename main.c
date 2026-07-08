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

static int	stacksize(t_stack *stack)
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

static t_stack	*printerror(t_stack **stack, char **split)
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
	return (NULL);
}

static t_stack	*set_stack(char **argv)
{
	t_stack *stack;
    char    **split;
    int     i;
    long    atol;

    stack = NULL;
	argv++;
    while (*argv)
    {
        i = 0;
        split = ft_split(*argv, ' ');
        while (split[i])
        {
            if (!is_number(split[i]))
                return printerror(&stack, split);
            atol = ft_atol(split[i]);
            if (atol > 2147483647 || atol < -2147483648 || is_duplicated(stack, (int)atol))
                return printerror(&stack, split);
            stackadd_back(&stack, stacknew((int)atol));
            i++;
        }
        free_split(split);
        argv++;
    }
    return (stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;
	float	disorder;

	if (argc < 2)
		return (0);
	stack_a = set_stack(argv);
	stack_b = NULL;
	disorder = compute_disorder(stack_a);
	if (disorder > 0.0)
    {
        if (disorder < 0.2)
            sort_2(&stack_a);
		else if (disorder >= 0.5)
            sort_3(&stack_a);
		else

        printstack(&stack_a, &stack_b);
    }
    stackclear(&stack_a);
    return (0);
}
