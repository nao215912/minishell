/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xdup2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:31:27 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/23 16:43:25 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	xdup2(int oldfd, int newfd)
{
	if (dup2(oldfd, newfd) == -1)
	{
		xperror("dup2: ");
		exit(EXIT_FAILURE);
	}
}
