/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:45:33 by nyokota           #+#    #+#             */
/*   Updated: 2022/01/13 19:47:21 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_signal.h"
#include "libft.h"
#include <errno.h>

static void	ft_heredoc_signal_sigint(int sig)
{
	(void)sig;
	ft_put_str_fd("\b\b  \b\b\n", 1);
	exit(1);
}

void	ft_heredoc_sig_hundler(void)
{
	if (signal(SIGINT, ft_heredoc_signal_sigint) == SIG_ERR || \
		signal(SIGQUIT, SIG_IGN) == SIG_ERR)
	{
		ft_put_str_fd(strerror(errno), STDERR_FILENO);
		exit(1);
	}
}
