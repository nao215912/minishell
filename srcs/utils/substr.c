/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:31:15 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/03 20:31:15 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*substr(char *start, char *end)
{
	char	*ret;
	size_t	idx;

	ret = xmalloc(sizeof(*ret) * (end - start + 1));
	idx = 0;
	while (start != end)
		ret[idx++] = *start++;
	ret[idx] = '\0';
	return (ret);
}
