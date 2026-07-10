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