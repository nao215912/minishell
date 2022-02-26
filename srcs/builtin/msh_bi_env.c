/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_bi_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:39:22 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/06 15:58:57 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "env.h"
#include "libft.h"

int	msh_bi_env(t_node *args, t_env **env)
{
	t_env	*cur;

	(void)args;
	cur = *env;
	while (cur)
	{
		ft_put_str_fd(cur->key, STDOUT_FILENO);
		ft_put_str_fd("=", STDOUT_FILENO);
		ft_putendl_fd(cur->value, STDOUT_FILENO);
		cur = cur->next;
	}
	return (0);
}
