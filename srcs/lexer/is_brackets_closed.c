/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_brackets_closed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:33:58 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/12 15:43:03 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"
#include "exit_status.h"

static void	skip_until_ch(char *str, size_t *idx, int c, bool *is_closed)
{
	++*idx;
	while (str[*idx] && str[*idx] != c)
		++*idx;
	if (!str[*idx])
		*is_closed = false;
}

bool	is_brackets_closed(char *line)
{
	size_t		idx;
	bool		is_closed;

	is_closed = true;
	idx = 0;
	while (line[idx] && is_closed)
	{
		if (line[idx] == '\'')
			skip_until_ch(line, &idx, '\'', &is_closed);
		if (line[idx] == '"')
			skip_until_ch(line, &idx, '"', &is_closed);
		++idx;
	}
	if (!is_closed)
	{
		set_exit_status(258);
		ft_putendl_fd("minishell"\
		": syntax error"\
		": unexpected end of file", \
		STDERR_FILENO);
	}
	return (is_closed);
}
