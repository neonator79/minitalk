/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysitkevi <ysitkevi@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:57:34 by ysitkevi          #+#    #+#             */
/*   Updated: 2024/08/07 21:57:36 by ysitkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(char const *sentence, ...);
void	inspect(va_list args, char *letter, size_t *number);
void	ft_putchar_printf(char c, size_t *number);
void	ft_putstr_printf(char *s, size_t *number);
void	ft_putnbr_printf(int n, size_t *number);
void	ft_putunsigned_printf(unsigned int n, size_t *number);
void	ft_putaddress_printf(void *address, size_t *number);
void	ft_puthexaup_printf(unsigned long long n, size_t *number);
void	ft_puthexadown_printf(unsigned long long n, size_t *number);

#endif
