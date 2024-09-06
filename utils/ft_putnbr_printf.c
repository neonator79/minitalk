/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysitkevi <ysitkevi@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 22:00:09 by ysitkevi          #+#    #+#             */
/*   Updated: 2024/08/07 22:00:15 by ysitkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_printf(int n, size_t *number)
{
	if (n == -2147483648)
	{
		ft_putstr_printf("-2147483648", number);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		ft_putchar_printf('-', number);
	}
	if (n > 9)
	{
		ft_putnbr_printf((n / 10), number);
		ft_putchar_printf(((n % 10) + 48), number);
	}
	else
		ft_putchar_printf((n + 48), number);
}
