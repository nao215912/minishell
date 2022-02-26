/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:34:51 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/03 17:34:51 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	token_clear(t_token *head)
{
	t_token	*next;

	while (head)
	{
		next = head->next;
		free(head);
		head = next;
	}
}
