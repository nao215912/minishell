/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_exec_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:43:59 by nyokota           #+#    #+#             */
/*   Updated: 2022/01/13 19:44:22 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "utils.h"
#include "exit_status.h"

static void	wait_child(pid_t *pids, size_t n)
{
	int		status;
	int		sig;
	size_t	idx;

	idx = 0;
	while (idx < n)
	{
		sig = 0;
		xwaitpid(pids[idx], &status, 0);
		if (WIFSIGNALED(status))
			sig = 128 + WTERMSIG(status);
		++idx;
	}
	if (sig)
		set_exit_status(sig);
	else
		set_exit_status(WEXITSTATUS(status));
}

void	cleanup_exec_command(pid_t *pids, size_t n, int read_fd)
{
	wait_child(pids, n);
	xclose(READ);
	xdup2(read_fd, READ);
	xclose(read_fd);
}
