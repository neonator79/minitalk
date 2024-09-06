/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexadown_printf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysitkevi <ysitkevi@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:59:18 by ysitkevi          #+#    #+#             */
/*   Updated: 2024/08/07 21:59:26 by ysitkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexadown_printf(unsigned long long n, size_t *number)
{
	char	storage[16];
	int		i;

	i = 0;
	if (n == 0)
	{
		ft_putchar_printf('0', number);
		return ;
	}
	while (n > 0)
	{
		if ((n % 16) > 9)
			storage[i] = (n % 16) + 87;
		else if ((n % 16) < 10)
			storage[i] = (n % 16) + 48;
		n /= 16;
		i ++;
	}
	while (i--)
		ft_putchar_printf(storage[i], number);
}
