/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysitkevi <ysitkevi@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:58:09 by ysitkevi          #+#    #+#             */
/*   Updated: 2024/08/07 21:58:11 by ysitkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putaddress_printf(void *address, size_t *number)
{
	unsigned long long	address2;

	address2 = (unsigned long long) address;
	ft_putstr_printf("0x", number);
	ft_puthexadown_printf(address2, number);
}
