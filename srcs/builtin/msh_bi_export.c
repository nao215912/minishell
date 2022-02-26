/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_bi_export.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:39:32 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/12 15:41:55 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "utils.h"
#include "env.h"
#include "expansion.h"

static bool	is_env_start_ch(int c)
{
	return ((c >= 'a' && c <= 'z') || \
			(c >= 'A' && c <= 'Z') || \
			c == '_');
}

static bool	is_env_str(char *start, char *end)
{
	if (!is_env_start_ch(*start))
		return (false);
	while (start != end && is_env_ch(*start))
		++start;
	return (start == end);
}

static void	print_error(t_node *args)
{
	ft_put_str_fd("minishell: export: `", STDERR_FILENO);
	ft_put_str_fd(args->str, STDERR_FILENO);
	ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
}

int	msh_bi_export(t_node *args, t_env **envp)
{
	char		*str;
	char		*key;
	char		*value;
	int			ret;

	ret = 0;
	while (args)
	{
		str = ft_strchr(args->str, '=');
		if (str && is_env_str(args->str, str))
		{
			key = substr(args->str, str);
			value = ft_strdup(++str);
			del_env(envp, key);
			add_env(envp, new_env(key, value));
		}
		else
		{
			print_error(args);
			ret = 1;
		}
		args = args->next;
	}
	return (ret);
}
