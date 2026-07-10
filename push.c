/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 01:02:57 by marvin            #+#    #+#             */
/*   Updated: 2026/07/07 01:02:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    void_push(t_stack **first_stack, t_stack **second_stack)
{
    t_stack *node;
    if (!*second_stack)
        return;
    node = *second_stack;
    *second_stack = (*second_stack)->next;
    if (*second_stack)
        (*second_stack)->prev = NULL;
    node->prev = NULL;
    node->next = NULL;
    stackadd_front(first_stack, node);
}

void    push_a(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
    void_push(stack_a, stack_b);
    ft_putstr_fd("pa\n", 1);
    if (bench && bench->active)
    {
        bench->pa++;
        bench->total_ops++;
    }
}

void    push_b(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
    void_push(stack_b, stack_a);
    ft_putstr_fd("pb\n", 1);
    if (bench && bench->active)
    {
        bench->pb++;
        bench->total_ops++;
    }
}