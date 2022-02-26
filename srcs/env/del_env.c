/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:20:34 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/12 14:49:05 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"

void	del_env(t_env **envp, char *key)
{
	t_env	*next;

	while (*envp)
	{
		if (!ft_strncmp(key, (*envp)->key, (*envp)->keylen))
		{
			next = (*envp)->next;
			free((*envp)->key);
			free((*envp)->value);
			free((*envp));
			*envp = next;
		}
		else
			envp = &(*envp)->next;
	}
}
