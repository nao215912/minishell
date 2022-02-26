/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:27:53 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/03 20:27:53 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

char	*ft_strdup(const char *str)
{
	char	*ret;
	size_t	idx;

	ret = xmalloc(ft_strlen(str));
	idx = 0;
	while (*str)
		ret[idx++] = *str++;
	ret[idx] = '\0';
	return (ret);
}
