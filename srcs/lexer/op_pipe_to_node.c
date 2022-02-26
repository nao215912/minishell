/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_pipe_to_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:34:24 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/15 16:19:54 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"
#include "exec.h"
#include "exit_status.h"

bool	op_pipe_to_node(t_token *this, t_executor *executor)
{
	(void)this;
	(void)executor;
	if (!this->prev || !this->next || this->next->operator == OP_PIPE)
	{
		ft_putendl_fd(SYNTAX_ERROR, STDERR_FILENO);
		set_exit_status(258);
		return (true);
	}
	return (false);
}
