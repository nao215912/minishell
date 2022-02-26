/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:21:16 by nyokota           #+#    #+#             */
/*   Updated: 2022/01/13 18:12:16 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "expansion.h"
#include "libft.h"
#include "utils.h"
#include "ft_signal.h"
#include "parser.h"
#include "ft_signal.h"
#include "exit_status.h"

static bool	parent_proc(int *pipe_fd)
{
	int		status;

	ft_parent_sig_hundler(SIG_IGN);
	xclose(pipe_fd[WRITE]);
	wait(&status);
	set_exit_status(WEXITSTATUS(status));
	if (WEXITSTATUS(status) == 1)
	{
		xclose(pipe_fd[READ]);
		return (true);
	}
	return (false);
}

static bool	child_proc(int *pipe_fd, t_node *redirect, t_env *env)
{
	char	*line;
	char	*expand_str;

	ft_heredoc_sig_hundler();
	xclose(pipe_fd[READ]);
	while (42)
	{
		line = readline("> ");
		if (!line)
			break ;
		expand_str = expand_env(env, line);
		if (!ft_strncmp(expand_str, redirect->str, \
			ft_strlen(redirect->str) + 1))
			break ;
		ft_putendl_fd(expand_str, pipe_fd[WRITE]);
		free(expand_str);
		free(line);
	}
	xclose(pipe_fd[WRITE]);
	free(line);
	exit(0);
}

static bool	here_doc(t_node *redirect, t_env *env)
{
	int		pipe_fd[PIPE];

	xpipe(pipe_fd);
	if (xfork())
	{
		if (parent_proc(pipe_fd))
			return (true);
	}
	else
		child_proc(pipe_fd, redirect, env);
	redirect->here_doc_fd = pipe_fd[READ];
	return (false);
}

bool	here_docs(t_executor *executor, t_env *env)
{
	t_node	*redirect;

	while (executor)
	{
		redirect = executor->redirect;
		while (redirect)
		{
			if (redirect->kind == TK_DRI && here_doc(redirect, env))
				return (true);
			redirect = redirect->next;
		}
		executor = executor->next;
	}
	return (false);
}
