/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_bi_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:39:14 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/23 16:46:01 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "parser.h"
#include "env.h"
#include "libft.h"
#include "exit_status.h"
#include "utils.h"

static void	msh_cd_error(char *path)
{
	path = ft_strjoin("cd: ", path);
	xperror(path);
	free(path);
}

int	msh_bi_cd(t_node *args, t_env **env)
{
	char	*path;

	(void)env;
	path = NULL;
	if (args)
		path = args->str;
	else
	{
		path = get_env(*env, "HOME");
		if (!*path)
		{
			ft_putendl_fd("minishell: cd: HOME not set", 2);
			return (1);
		}
	}
	if (chdir(path) != 0)
	{
		msh_cd_error(path);
		return (1);
	}
	return (0);
}
