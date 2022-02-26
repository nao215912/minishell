/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:20:28 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/03 17:20:28 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	clear_env(t_env *head)
{
	t_env	*next;

	while (head)
	{
		next = head->next;
		free(head->key);
		free(head->value);
		free(head);
		head = next;
	}
}
