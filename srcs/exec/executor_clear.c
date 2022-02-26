/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:21:01 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/03 21:38:29 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "parser.h"

void	executor_clear(t_executor *head)
{
	t_executor	*next;

	while (head)
	{
		next = head->next;
		node_clear(head->redirect);
		node_clear(head->command);
		free(head);
		head = next;
	}
}
