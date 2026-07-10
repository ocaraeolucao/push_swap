/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luvieira <luvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 18:21:53 by luvieira          #+#    #+#             */
/*   Updated: 2026/07/08 20:45:07 by luvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stackclear(t_stack **stack)
{
	t_stack	*next;

	if (!stack)
		return ;
	while (*stack)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
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
	ft_putstr_fd("Error\n", 2);
	free_split(split);
	stackclear(stack);
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
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_strategy	strategy;
	t_bench     bench;

	ft_bzero(&bench, sizeof(t_bench));
	strategy = ADAPTIVE;
	if (!set_options(&bench, &strategy, &argc, &argv) || argc < 2)
		return (0);
	stack_a = set_stack(argv);
	stack_b = NULL;
	master_sort(&stack_a, &stack_b, strategy, &bench);
	printbench(bench);
    stackclear(&stack_a);
    return (0);
}
