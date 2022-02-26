/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xwaitpid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:23:56 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/23 18:29:07 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

pid_t	xwaitpid(pid_t pid, int *status, int mode)
{
	pid_t	ret;

	ret = waitpid(pid, status, mode);
	if (ret == -1)
	{
		xperror("waitpid");
		exit(EXIT_FAILURE);
	}
	return (ret);
}
