/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 15:09:18 by marvin            #+#    #+#             */
/*   Updated: 2026/07/10 15:09:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putfloat_fd(float f, int fd)
{
	int	int_part;
	int	frac_part;

	int_part = (int)f;
	frac_part = (int)(((f - (float)int_part) * 100.0) + 0.5);
	ft_putnbr_fd(int_part, fd);
	ft_putchar_fd('.', fd);
	if (frac_part < 10)
		ft_putnbr_fd(0, fd);
	ft_putnbr_fd(frac_part, fd);
}
