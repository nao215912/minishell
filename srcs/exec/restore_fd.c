/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:21:30 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/03 17:21:30 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "parser.h"

void	restore_fd(t_node *node)
{
	if (!node)
		return ;
	restore_fd(node->next);
	if (node->dup_fd >= 0)
	{
		xdup2(node->dup_fd, node->fd);
		xclose(node->dup_fd);
	}
}
