/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luvieira <luvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 18:27:06 by luvieira          #+#    #+#             */
/*   Updated: 2026/06/30 20:35:30 by luvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"


typedef struct s_stack
{
	int				number;
	struct s_stack	*before;
	struct s_stack	*next;
}	t_stack;

int		main(int argc, char **argv);
t_stack	*stacklast(t_stack *stack);
t_stack	*stacknew(int number);
void	stackadd_back(t_stack **stack, t_stack *new);


#endif