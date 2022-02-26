/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:29:39 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/03 20:29:39 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	node_clear(t_node *head)
{
	t_node	*next;

	while (head)
	{
		next = head->next;
		free(head->str);
		free(head);
		head = next;
	}
}
