/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ro_to_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:34:33 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/03 21:14:53 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "parser.h"
#include "utils.h"
#include "exec.h"

bool	op_ro_to_node(t_token *this, t_executor *executor)
{
	t_node	*node;

	node = xmalloc(sizeof(*node));
	if (op_to_node(this, node, TK_RO, STDOUT_FILENO))
		return (true);
	node_add_back(&(executor->redirect), node);
	return (false);
}
