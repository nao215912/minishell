/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:27:56 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/03 20:27:56 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	dest = xmalloc(sizeof(*dest) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	i = 0;
	while (*s1)
		dest[i++] = *s1++;
	while (*s2)
		dest[i++] = *s2++;
	dest[i] = '\0';
	return (dest);
}
