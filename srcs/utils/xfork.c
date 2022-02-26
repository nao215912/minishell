/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:31:53 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/23 16:43:30 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

pid_t	xfork(void)
{
	pid_t	ret;

	ret = fork();
	if (ret == -1)
	{
		xperror("fork: ");
		exit(EXIT_FAILURE);
	}
	return (ret);
}
