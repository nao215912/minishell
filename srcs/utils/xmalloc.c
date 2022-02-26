/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:31:57 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/23 16:43:35 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*xmalloc(size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (!ret)
	{
		xperror("malloc");
		exit(EXIT_FAILURE);
	}
	return (ret);
}
