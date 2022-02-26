/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:20:37 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/12 14:47:51 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"

char	*get_env(t_env *env, char *key)
{
	if (!*key)
		return ("$");
	while (env)
	{
		if (!ft_strncmp(key, env->key, env->keylen))
			return (env->value);
		env = env->next;
	}
	return ("");
}
