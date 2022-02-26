/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:20:47 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/12 14:50:28 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "utils.h"
#include "libft.h"

t_env	*new_env(char *key, char *value)
{
	t_env	*ret;

	ret = xmalloc(sizeof(*ret));
	ret->key = key;
	ret->value = value;
	ret->keylen = ft_strlen(key) + 1;
	ret->next = NULL;
	return (ret);
}
