/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:34:03 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/03 17:34:03 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "lexer.h"
#include "libft.h"

static const char	*get_op_str(t_op_idx op_idx)
{
	static const char	*op_str[] = \
	{
		"<<",
		"<",
		">>",
		">",
		"|",
		NULL
	};

	return (op_str[op_idx]);
}

static t_op_idx	get_op_idx(char *str)
{
	t_op_idx	op_idx;

	op_idx = 0;
	while (get_op_str(op_idx))
	{
		if (!ft_strncmp(str, get_op_str(op_idx), ft_strlen(get_op_str(op_idx))))
			return (op_idx);
		++op_idx;
	}
	return (op_idx);
}

static char	*skip_idx(char *str, size_t *idx)
{
	while (str[*idx])
	{
		if (str[*idx] == '"')
			skip_until_ch(str, idx, '"');
		else if (str[*idx] == '\'')
			skip_until_ch(str, idx, '\'');
		else if (get_op_idx(&str[*idx]) != OP_OTHER)
			return (&str[*idx]);
		else if (is_space(str[*idx]))
			return (&str[*idx]);
		else
			++*idx;
	}
	return (&str[*idx]);
}

static void	op_idx_is_op_other(t_token *token, char *line, size_t *idx)
{
	size_t	start;

	start = *idx;
	token->str = substr(&line[start], skip_idx(line, idx));
	if (is_number_string(token->str))
	{
		token->operator = get_op_idx(&line[*idx]);
		if (token->operator == OP_PIPE)
			token->operator = OP_OTHER;
		else if (token->operator != OP_OTHER)
			*idx += ft_strlen(get_op_str(token->operator));
	}
}

t_token	*lexer(char *line)
{
	t_token	*head;
	t_token	**cur;
	t_token	*prev;
	size_t	idx;

	head = NULL;
	prev = NULL;
	cur = &head;
	idx = 0;
	while (skip_space(line, &idx), line[idx])
	{
		*cur = xmalloc(sizeof(**cur));
		**cur = (t_token){};
		(*cur)->operator = get_op_idx(&line[idx]);
		if ((*cur)->operator == OP_OTHER)
			op_idx_is_op_other(*cur, line, &idx);
		else
			idx += ft_strlen(get_op_str((*cur)->operator));
		(*cur)->prev = prev;
		(*cur)->to_node = get_op_func((*cur)->operator);
		prev = *cur;
		cur = &(*cur)->next;
	}
	free(line);
	return (head);
}
