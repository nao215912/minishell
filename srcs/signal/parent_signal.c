/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:30:04 by nyokota           #+#    #+#             */
/*   Updated: 2022/01/13 19:48:37 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_signal.h"
#include "libft.h"
#include <errno.h>
#include "exit_status.h"

void	ft_parent_signal_sigint(int sig)
{
	(void)sig;
	ft_put_str_fd("\b\b  \b\b\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	set_exit_status(errno = 1);
}

void	ft_parent_sig_hundler(void (*func)(int sig))
{
	if (func == NULL)
		return ;
	if (signal(SIGINT, func) == SIG_ERR || \
		signal(SIGQUIT, SIG_IGN) == SIG_ERR)
	{
		ft_put_str_fd(strerror(errno), STDERR_FILENO);
		exit(1);
	}
}
