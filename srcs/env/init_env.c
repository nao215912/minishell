/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:20:42 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/12 14:47:43 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "utils.h"
#include "libft.h"

t_env	*init_env(char **envp)
{
	t_env	*head;
	t_env	**cur;
	char	*str;

	head = NULL;
	cur = &head;
	while (*envp)
	{
		*cur = xmalloc(sizeof(**cur));
		str = *envp;
		while (*str && *str != '=')
			++str;
		*str = '\0';
		(*cur)->key = ft_strdup(*envp++);
		(*cur)->keylen = ft_strlen((*cur)->key) + 1;
		(*cur)->value = ft_strdup(++str);
		(*cur)->next = NULL;
		cur = &(*cur)->next;
	}
	return (head);
}
