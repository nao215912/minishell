/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_to_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:34:37 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/12 15:13:58 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "parser.h"
#include "utils.h"
#include "libft.h"
#include "exec.h"
#include "exit_status.h"
#include <limits.h>

static bool	set_fd(char *str, int fd, t_node *node)
{
	bool	is_over_flow;

	if (str)
	{
		node->fd = msh_atoi(str, &is_over_flow);
		if (is_over_flow)
		{
			free(node);
			ft_putendl_fd(BAD_FD, STDERR_FILENO);
			set_exit_status(1);
			return (true);
		}
	}
	else
		node->fd = fd;
	return (false);
}

bool	op_to_node(t_token *token, t_node *node, t_kind kind, int fd)
{
	if (!token->next || token->next->operator != OP_OTHER)
	{
		ft_putendl_fd(SYNTAX_ERROR, STDERR_FILENO);
		set_exit_status(258);
		return (true);
	}
	node->kind = kind;
	if (set_fd(token->str, fd, node))
		return (true);
	node->dup_fd = INT_MIN;
	node->str = token->next->str;
	remove_brackets(node->str);
	node->next = NULL;
	return (false);
}
