/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_bi_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:39:39 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/12 15:40:02 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "env.h"
#include "utils.h"
#include "libft.h"
#include "expansion.h"

static bool	is_env_start_ch(int c)
{
	return ((c >= 'a' && c <= 'z') || \
			(c >= 'A' && c <= 'Z') || \
			c == '_');
}

static bool	is_env_str(char *str)
{
	if (!is_env_start_ch(*str))
		return (false);
	while (*str && is_env_ch(*str))
		++str;
	return (!*str);
}

int	msh_bi_unset(t_node *args, t_env **envp)
{
	int	ret;

	ret = 0;
	while (args)
	{
		if (is_env_str(args->str))
			del_env(envp, args->str);
		else
		{
			ft_put_str_fd("minishell: unset: `", STDERR_FILENO);
			ft_put_str_fd(args->str, STDERR_FILENO);
			ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
			ret = 1;
		}
		args = args->next;
	}
	return (ret);
}
