/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:20:57 by nyokota           #+#    #+#             */
/*   Updated: 2022/01/13 19:43:41 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "env.h"
#include "utils.h"
#include "libft.h"
#include "parser.h"
#include "builtin.h"
#include "exit_status.h"
#include "ft_signal.h"

static void	child_process(t_executor *executor, t_env **env, \
							int *pipe_fd)
{
	xclose(pipe_fd[READ]);
	if (executor->next)
		xdup2(pipe_fd[WRITE], WRITE);
	xclose(pipe_fd[WRITE]);
	if (setup_redirects(executor->redirect))
		exit(EXIT_FAILURE);
	if (is_builtin(executor->command))
		exit(exec_builtin(executor, env));
	if (executor->command)
		execve(format_path(executor->command->str, \
				ft_split(get_env(*env, "PATH"), ':')), \
				format_command(executor->command), NULL);
}

static void	adult_process(int *pipe_fd)
{
	xclose(pipe_fd[WRITE]);
	xdup2(pipe_fd[READ], READ);
	xclose(pipe_fd[READ]);
}

void	exec_command(t_executor *executor, t_env **env)
{
	int		pipe_fd[PIPE];
	int		read_fd;
	size_t	n;
	pid_t	pids[800];

	if (prepare_exec_command(executor, env))
		return ;
	read_fd = xdup(READ);
	n = 0;
	while (executor)
	{
		xpipe(pipe_fd);
		pids[n] = xfork();
		if (!pids[n++])
			child_process(executor, env, pipe_fd);
		else
			adult_process(pipe_fd);
		executor = executor->next;
	}
	cleanup_exec_command(pids, n, read_fd);
}
