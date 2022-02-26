/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_bi_echo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:39:18 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/12 10:57:15 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "parser.h"
#include "libft.h"

static bool	ft_is_option(t_node *args)
{
	char	*str;
	size_t	i;

	if (!args)
		return (false);
	str = args->str;
	i = 0;
	if (str[i++] != '-')
		return (false);
	while (str[i])
	{
		if (str[i++] != 'n')
			return (false);
	}
	return (true);
}

int	msh_bi_echo(t_node *args, t_env **env)
{
	bool	is_endl;

	(void)env;
	is_endl = false;
	while (ft_is_option(args))
	{
		is_endl = true;
		args = args->next;
	}
	while (args)
	{
		ft_put_str_fd(args->str, STDOUT_FILENO);
		if (args->next)
			ft_put_str_fd(" ", STDOUT_FILENO);
		args = args->next;
	}
	if (!is_endl)
		ft_put_str_fd("\n", STDOUT_FILENO);
	return (0);
}
