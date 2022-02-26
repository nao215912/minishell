/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:45:09 by nyokota           #+#    #+#             */
/*   Updated: 2022/01/13 19:47:44 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_signal.h"
#include "libft.h"
#include <errno.h>
#include "exit_status.h"

static void	ft_child_signal_sigint(int sig)
{
	(void)sig;
	ft_put_str_fd("\n", 1);
}

static void	ft_child_signal_sigquit(int sig)
{
	(void)sig;
}

void	ft_child_sig_hundler(void)
{
	if (signal(SIGINT, ft_child_signal_sigint) == SIG_ERR || \
		signal(SIGQUIT, ft_child_signal_sigquit) == SIG_ERR)
	{
		ft_put_str_fd(strerror(errno), STDERR_FILENO);
		exit(1);
	}
}
