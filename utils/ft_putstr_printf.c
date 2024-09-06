/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysitkevi <ysitkevi@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 22:00:32 by ysitkevi          #+#    #+#             */
/*   Updated: 2024/08/07 22:00:34 by ysitkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_printf(char *s, size_t *number)
{
	if (!s)
	{
		ft_putstr_printf("(null)", number);
		return ;
	}
	while (*s != '\0')
	{
		ft_putchar_printf(*s, number);
		s++;
	}
}
