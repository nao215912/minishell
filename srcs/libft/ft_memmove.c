/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:27:20 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/03 20:27:20 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*from;
	unsigned char	*to;
	size_t			idx;

	if (dest == src || n == 0)
		return (dest);
	from = (unsigned char *)src;
	to = (unsigned char *)dest;
	if (to > from)
		while (--n)
			to[n] = from[n];
	else
	{
		idx = 0;
		while (idx < n)
		{
			to[idx] = from[idx];
			++idx;
		}
	}
	return (dest);
}
