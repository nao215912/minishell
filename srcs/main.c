/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:30:13 by nyokota           #+#    #+#             */
/*   Updated: 2022/01/10 21:02:01 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "exec.h"
#include "lexer.h"
#include "libft.h"
#include "parser.h"
#include "ft_signal.h"
#include "utils.h"
#include "expansion.h"
#include "exit_status.h"
#include <readline/readline.h>
#include <readline/history.h>

static void	minishell_logic(char *line, t_env **env)
{
	t_executor	*executor;

	executor = parser(lexer(expansion(*env, line)));
	if (executor)
		exec_command(executor, env);
	executor_clear(executor);
}

static void	minishell_loop(t_env **env)
{
	char		*line;

	while (42)
	{
		ft_parent_sig_hundler(ft_parent_signal_sigint);
		line = readline("minishell$ ");
		if (!line)
		{
			printf("exit\n");
			exit(ft_atoi(get_exit_status()));
		}
		if (ft_strlen(line) > 0)
			add_history(line);
		if (is_brackets_closed(line))
			minishell_logic(line, env);
		free(line);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_env	*env;

	(void)argv;
	(void)argc;
	env = init_env(envp);
	set_exit_status(0);
	minishell_loop(&env);
	return (0);
}
