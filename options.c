/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 00:37:50 by marvin            #+#    #+#             */
/*   Updated: 2026/07/10 00:37:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void printoperations(t_bench bench)
{
	ft_putstr_fd("\n[bench] total_ops:	", 2);
	ft_putnbr_fd(bench.total_ops, 2);
	ft_putstr_fd("\n[bench] sa:	", 2);
	ft_putnbr_fd(bench.sa, 2);
	ft_putstr_fd("	sb:	", 2);
	ft_putnbr_fd(bench.sb, 2);
	ft_putstr_fd("	ss:	", 2);
	ft_putnbr_fd(bench.ss, 2);
	ft_putstr_fd("	pa:	", 2);
	ft_putnbr_fd(bench.pa, 2);
	ft_putstr_fd("	pb:	", 2);
	ft_putnbr_fd(bench.pb, 2);
	ft_putstr_fd("\n[bench] ra:	", 2);
	ft_putnbr_fd(bench.ra, 2);
	ft_putstr_fd("	rb:	", 2);
	ft_putnbr_fd(bench.rb, 2);
	ft_putstr_fd("	rr:	", 2);
	ft_putnbr_fd(bench.rr, 2);
	ft_putstr_fd("	rra:	", 2);
	ft_putnbr_fd(bench.rra, 2);
	ft_putstr_fd("	rrb:	", 2);
	ft_putnbr_fd(bench.rrb, 2);
	ft_putstr_fd("	rrr:	", 2);
	ft_putnbr_fd(bench.rrr, 2);
    ft_putstr_fd("\n", 2);
}

void	printbench(t_bench bench)
{
	if (bench.active != 1)
		return ;
	ft_putstr_fd("[bench] disorder:	", 2);
	ft_putfloat_fd(bench.disorder, 2);
	ft_putstr_fd("%\n[bench] strategy:	", 2);
	ft_putstr_fd(bench.strategy_name, 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd(bench.complexity, 2);
	printoperations(bench);
}

char    *set_strategy_name(t_strategy strategy)
{
    if (strategy == SIMPLE)
        return ("Selection sort adaptation");
    else if (strategy == MEDIUM)
        return ("Chunk-based sortin");
    else if (strategy == COMPLEX)
        return ("Radix sort adaptation");
    else
        return ("Adaptive");
}

char    *set_complexity(t_strategy strategy)
{
    if (strategy == SIMPLE)
        return ("O(n^2)");
    else if (strategy == MEDIUM)
        return ("O(n√n)");
    else if (strategy == COMPLEX)
        return ("O(n log n)");
    else
        return ("O(1)");
}

int set_options(t_bench *bench, t_strategy *strategy, int *argc, char ***argv)
{
    while (*argc > 1 && ft_strncmp((*argv)[1], "--", 2) == 0)
    {
        if (ft_strncmp((*argv)[1], "--bench", 8) == 0)
            (*bench).active = 1;
        else if (ft_strncmp((*argv)[1], "--simple", 9) == 0)
            *strategy = SIMPLE;
        else if (ft_strncmp((*argv)[1], "--medium", 9) == 0)
            *strategy = MEDIUM;
        else if (ft_strncmp((*argv)[1], "--complex", 10) == 0)
            *strategy = COMPLEX;
        else if (ft_strncmp((*argv)[1], "--adaptive", 11) == 0)
            *strategy = ADAPTIVE;
        else
        {
            ft_putstr_fd("Error\n", 2);
            return (0);
        }
        (*argv)++;
        (*argc)--;
    }
    return (1);
}
