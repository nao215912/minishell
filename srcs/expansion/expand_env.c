/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:32:17 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/03 17:33:25 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "env.h"
#include "expansion.h"
#include "exit_status.h"
#include "utils.h"

static char	*ch_is_dollar(t_env *env, char *str, size_t *idx, char *dst)
{
	char	*ret;
	char	*start;
	char	c;

	start = &str[++*idx];
	if (str[*idx] == '?')
	{
		ret = ft_strjoin(dst, get_exit_status());
		++*idx;
	}
	else
	{
		while (is_env_ch(str[*idx]))
			++*idx;
		c = str[*idx];
		str[*idx] = '\0';
		ret = ft_strjoin(dst, get_env(env, start));
		if (c)
			str[*idx++] = c;
	}
	return (ret);
}

static char	*ch_is_not_dollar(char *str, size_t *idx, char *dst)
{
	char	*ret;
	char	*start;
	char	c;

	start = &str[*idx];
	while (str[*idx] && str[*idx] != '$')
		++*idx;
	c = str[*idx];
	str[*idx] = '\0';
	ret = ft_strjoin(dst, start);
	if (c)
		str[*idx++] = c;
	return (ret);
}

char	*expand_env(t_env *env, char *str)
{
	char	*ret;
	char	*tmp;
	size_t	idx;

	ret = ft_strdup("");
	idx = 0;
	while (str[idx])
	{
		tmp = ret;
		if (str[idx] == '$')
			ret = ch_is_dollar(env, str, &idx, ret);
		else
			ret = ch_is_not_dollar(str, &idx, ret);
		free(tmp);
	}
	return (ret);
}
