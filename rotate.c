/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 23:27:01 by marvin            #+#    #+#             */
/*   Updated: 2026/07/06 23:27:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    void_rotate(t_stack **stack)
{
    t_stack *first_stack;
    t_stack *second_stack;

    if (!*stack || !(*stack)->next)
        return ;
    first_stack = *stack;
    second_stack = (*stack)->next;
    second_stack->prev = NULL;
    *stack = second_stack;
    first_stack->next = NULL;
    stackadd_back(stack, first_stack);
}

void    rotate_a(t_stack **stack_a)
{
    void_rotate(stack_a);
    ft_putstr_fd("ra\n", 1);
}

void    rotate_b(t_stack **stack_b)
{
    void_rotate(stack_b);
    ft_putstr_fd("rb\n", 1);
}

void    rotate_r(t_stack **stack_a, t_stack **stack_b)
{
    void_rotate(stack_a);
    void_rotate(stack_b);
    ft_putstr_fd("rr\n", 1);
}