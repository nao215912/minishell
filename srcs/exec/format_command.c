/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:21:06 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/03 17:21:06 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "utils.h"

static char	**rec(t_node *node, size_t idx)
{
	char	**ret;

	if (!node)
	{
		ret = xmalloc(sizeof(*ret) * (idx + 1));
		ret[idx] = NULL;
		return (ret);
	}
	ret = rec(node->next, idx + 1);
	if (ret)
		ret[idx] = node->str;
	return (ret);
}

char	**format_command(t_node *node)
{
	return (rec(node, 0ULL));
}
