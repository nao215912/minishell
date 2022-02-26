/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xdup.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:31:23 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/23 16:43:19 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	xdup(int oldfd)
{
	int	ret;

	ret = dup(oldfd);
	if (ret == -1)
	{
		xperror("dup: ");
		exit(EXIT_FAILURE);
	}
	return (ret);
}
