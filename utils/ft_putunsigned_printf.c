/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_printf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysitkevi <ysitkevi@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 22:00:48 by ysitkevi          #+#    #+#             */
/*   Updated: 2024/08/07 22:00:51 by ysitkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsigned_printf(unsigned int n, size_t *number)
{
	if (n > 9)
	{
		ft_putunsigned_printf((n / 10), number);
		ft_putchar_printf(((n % 10) + 48), number);
	}
	else
		ft_putchar_printf((n + 48), number);
}
