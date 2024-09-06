/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysitkevi <ysitkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:55:52 by ysitkevi          #+#    #+#             */
/*   Updated: 2024/08/08 20:31:20 by ysitkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/ft_printf.h"
#include "utils/libft.h"

int		g_confirmation;

void	send_char(char letter, pid_t pid)
{
	int	bit;

	bit = __CHAR_BIT__ * sizeof(char) - 1;
	while (bit >= 0)
	{
		g_confirmation = 0;
		if ((letter >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit--;
		while (g_confirmation != 1)
			usleep(10);
	}
}

void	send_str(char *str, pid_t pid)
{
	int	cur;

	cur = 0;
	while (str[cur])
	{
		send_char(str[cur], pid);
		cur++;
	}
	send_char('\n', pid);
	send_char(0, pid);
}

void	sig_usr_handler(int signal)
{
	if (signal == SIGUSR1)
		g_confirmation = 1;
	else if (signal == SIGUSR2)
		exit(0);
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_printf("¡SIN ARGUMENTOS! :3\n");
		return (1);
	}
	signal(SIGUSR1, &sig_usr_handler);
	signal(SIGUSR2, &sig_usr_handler);
	pid = ft_atoi(argv[1]);
	send_str(argv[2], pid);
	while (1)
		sleep(1);
}
