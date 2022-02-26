/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_sp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:32:22 by nyokota           #+#    #+#             */
/*   Updated: 2022/01/09 17:13:46 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"
#include "env.h"

char	*expansion_sp(t_env *env, char *str, size_t *idx)
{
	char	*ret;
	char	*start;
	char	c;

	start = &str[*idx];
	while (str[*idx] && str[*idx] != '\'' && str[*idx] != '"')
		++*idx;
	c = str[*idx];
	str[*idx] = '\0';
	ret = expand_env(env, start);
	if (c)
		str[*idx++] = c;
	return (ret);
}
