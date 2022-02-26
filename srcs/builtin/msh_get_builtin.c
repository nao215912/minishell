/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_get_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:39:43 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/03 17:19:55 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "libft.h"

const t_builtin	*msh_get_builtin(char *command)
{
	static const t_builtin	builtins[] = \
	{
		(t_builtin){"cd", msh_bi_cd},
		(t_builtin){"echo", msh_bi_echo},
		(t_builtin){"env", msh_bi_env},
		(t_builtin){"exit", msh_bi_exit},
		(t_builtin){"export", msh_bi_export},
		(t_builtin){"pdw", msh_bi_pwd},
		(t_builtin){"unset", msh_bi_unset}
	};
	t_builtin_idx			idx;

	idx = 0;
	while (idx < BI_OTHER)
	{
		if (!ft_strncmp(command, builtins[idx].name, \
			ft_strlen(builtins[idx].name)))
			return (&builtins[idx]);
		++idx;
	}
	return (NULL);
}
