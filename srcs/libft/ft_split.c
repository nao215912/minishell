/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:27:45 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/03 20:27:46 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

static char	**rec_split(char *str, const char c, size_t idx)
{
	char	**ret;
	char	*ptr;

	while (*str && *str == c)
		++str;
	if (!*str)
	{
		ret = xmalloc(sizeof(*ret) * (idx + 1));
		ret[idx] = NULL;
		return (ret);
	}
	ptr = (char *)str;
	while (*str && *str != c)
		++str;
	ptr = substr(ptr, str);
	ret = rec_split(str, c, idx + 1);
	ret[idx] = ptr;
	return (ret);
}

char	**ft_split(char *s, char c)
{
	if (!s)
		return (NULL);
	return (rec_split((char *)s, c, 0));
}
