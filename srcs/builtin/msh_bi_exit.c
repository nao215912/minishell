/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_bi_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:39:26 by nyokota           #+#    #+#             */
/*   Updated: 2022/01/09 19:02:41 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include <limits.h>
#include "exec.h"
#include "parser.h"
#include "libft.h"
#include "exit_status.h"
#include <errno.h>
#include "utils.h"

static void	exit_numeric_argument_error(char *str)
{
	ft_put_str_fd("minishell: exit: ", STDERR_FILENO);
	ft_put_str_fd(str, STDERR_FILENO);
	ft_putendl_fd(": numeric argument required", STDERR_FILENO);
}

static void	exit_too_many_argument_error(void)
{
	ft_putendl_fd("minishell: exit: too many arguments", STDERR_FILENO);
}

static int	exit_atoi(const char *str, bool *err_flg)
{
	long	res;
	int		negative;

	res = 0;
	negative = 1;
	*err_flg = false;
	while (is_space(*str))
		++str;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			negative *= -1;
	if (!*str)
		return (*err_flg = true);
	while (*str >= '0' && *str <= '9')
	{
		if ((res * 10 + (*str - '0')) / 10 != res)
			break ;
		res = res * 10 + (*str++ - '0');
	}
	while (is_space(*str))
		++str;
	if (*str)
		*err_flg = true;
	return (res * negative);
}

int	msh_bi_exit(t_node *args, t_env **env)
{
	bool		err_flg;
	int			exit_status;

	(void)env;
	ft_putendl_fd("exit", STDERR_FILENO);
	if (args == NULL)
		exit(0);
	if (!ft_strncmp(args->str, "--", 3))
		args = args->next;
	if (!args)
		exit(ft_atoi(get_exit_status()));
	exit_status = exit_atoi(args->str, &err_flg);
	if (err_flg)
	{
		exit_numeric_argument_error(args->str);
		exit(255);
	}
	else if (args->next)
		return (exit_too_many_argument_error(), 1);
	else
		exit((uint8_t)exit_status);
	return (0);
}
