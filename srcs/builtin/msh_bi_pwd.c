/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_bi_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:39:35 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/23 16:42:50 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "libft.h"
#include "env.h" 
#include <limits.h>
#include <utils.h>

int	msh_bi_pwd(t_node *args, t_env **env)
{
	char	path[PATH_MAX];

	(void)env;
	(void)args;
	if (!getcwd(path, sizeof(path)))
		xperror("pwd: ");
	ft_putendl_fd(path, STDOUT_FILENO);
	return (0);
}
