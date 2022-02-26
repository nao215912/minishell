/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_other_to_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:34:19 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/03 17:34:19 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "parser.h"
#include "utils.h"
#include "exec.h"

bool	op_other_to_node(t_token *this, t_executor *executor)
{
	t_node	*node;

	if (this->prev && \
		!(this->prev->operator == OP_OTHER || \
		this->prev->operator == OP_PIPE))
		return (false);
	node = xmalloc(sizeof(*node));
	node->kind = TK_CMD;
	node->str = this->str;
	remove_brackets(node->str);
	node->next = NULL;
	node_add_back(&(executor->command), node);
	return (false);
}
