/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_dq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:32:39 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/23 18:42:00 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "env.h"
#include "expansion.h"

char	*expansion_dq(t_env *env, char *str, size_t *idx)
{
	char	*ret;
	char	*start;
	char	c;

	start = &str[*idx];
	skip_until_ch(str, idx, '"');
	c = str[*idx];
	str[*idx] = '\0';
	ret = expand_env(env, start);
	if (c)
		str[*idx++] = c;
	return (ret);
}
