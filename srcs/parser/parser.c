/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:29:43 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/03 20:29:43 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "parser.h"
#include "exec.h"
#include "utils.h"

t_executor	*parser(t_token *token)
{
	t_executor		*head;
	t_executor		**cur;
	t_token			*token_head;

	token_head = token;
	head = NULL;
	cur = &head;
	while (token)
	{
		if (token->operator == OP_PIPE && *cur)
			cur = &(*cur)->next;
		if (!*cur)
		{
			*cur = xmalloc(sizeof(**cur));
			**cur = (t_executor){};
		}
		if (token->to_node(token, *cur))
			return (executor_clear(head), token_clear(token_head), NULL);
		token = token->next;
	}
	return (token_clear(token_head), head);
}
