/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_exec_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:44:07 by nyokota           #+#    #+#             */
/*   Updated: 2022/01/13 19:44:33 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "env.h"
#include "exec.h"
#include "ft_signal.h"
#include "exit_status.h"
#include "builtin.h"

static void	adult_exec_builtin(t_executor *executor, t_env **env)
{
	if (setup_redirects(executor->redirect))
		set_exit_status(EXIT_FAILURE);
	else
	{
		set_exit_status(exec_builtin(executor, env));
		restore_fd(executor->redirect);
	}
}

bool	prepare_exec_command(t_executor *executor, t_env **env)
{
	if (here_docs(executor, *env))
		return (true);
	ft_child_sig_hundler();
	if (is_builtin(executor->command) && !executor->next)
	{
		adult_exec_builtin(executor, env);
		return (true);
	}
	return (false);
}
