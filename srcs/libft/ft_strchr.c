/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:27:50 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/03 20:27:50 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*((unsigned char *)s) == (unsigned char)c)
			return ((char *)s);
		++s;
	}
	if (!c)
		return ((char *)s);
	return (NULL);
}
