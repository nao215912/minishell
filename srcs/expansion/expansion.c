/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:32:34 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/23 18:36:45 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"
#include "libft.h"
#include "env.h"

char	*expansion(t_env *env, char *line)
{
	char	*ret;
	char	*tmp_ret;
	char	*add;
	size_t	idx;

	ret = ft_strdup("");
	idx = 0;
	while (line[idx])
	{
		tmp_ret = ret;
		if (line[idx] == '\'')
			ret = ft_strjoin(ret, add = expansion_sq(line, &idx));
		else if (line[idx] == '"')
			ret = ft_strjoin(ret, add = expansion_dq(env, line, &idx));
		else
			ret = ft_strjoin(ret, add = expansion_sp(env, line, &idx));
		free(tmp_ret);
		free(add);
	}
	return (ret);
}
