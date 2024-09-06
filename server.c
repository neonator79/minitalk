/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysitkevi <ysitkevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 21:55:00 by ysitkevi          #+#    #+#             */
/*   Updated: 2024/08/08 20:30:09 by ysitkevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_C_SOURCE 200809L
#include "./utils/ft_printf.h"
#include "./utils/libft.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int		g_bit_init;

void	sig_handler(int signal, siginfo_t *pid, void *opcional)
{
	static char	letter;
	static int	bit;

	(void)opcional;
	if (!g_bit_init)
	{
		bit = -1;
		g_bit_init = 1;
	}
	if (bit < 0)
		bit = __CHAR_BIT__ * sizeof(char) - 1;
	if (kill(pid->si_pid, 0) < 0)
		exit(1);
	if (signal == SIGUSR1)
		letter = (letter | (1 << bit));
	else if (signal == SIGUSR2)
		letter = (letter & ~(1 << bit));
	if (!bit && letter)
		ft_putchar_fd(letter, 1);
	else if (!bit && !letter)
		kill(pid->si_pid, SIGUSR2);
	bit--;
	kill(pid->si_pid, SIGUSR1);
}

void	sigaction_set(int signal, void (*signal_handler)(int, siginfo_t *,
			void *))
{
	struct sigaction	susr;

	susr.sa_sigaction = signal_handler;
	susr.sa_flags = SA_SIGINFO | SA_RESTART | SA_NODEFER;
	sigemptyset(&susr.sa_mask);
	if (signal == SIGUSR1)
		sigaction(SIGUSR1, &susr, 0);
	else if (signal == SIGUSR2)
		sigaction(SIGUSR2, &susr, 0);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("╔━┓┏━╦━━━╦━┓ ╔━┓ ╔━━╗\n");
	ft_printf("║ ┗┛ ║ ┗━╣ ┃ ║ ┃ ║╯╰║\n");
	ft_printf("║ ┏┓ ║ ┏━╣ ┗━╣ ┗━╣╰╯║\n");
	ft_printf("╚━┛┗━╩━━━╩━━━╩━━━╩━━╝\n");
	ft_printf("\t\t\tpid: %d\n", pid);
	sigaction_set(SIGUSR1, &sig_handler);
	sigaction_set(SIGUSR2, &sig_handler);
	while (1)
		sleep(1);
}
