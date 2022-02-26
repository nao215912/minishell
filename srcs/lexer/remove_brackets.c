/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_brackets.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:34:46 by nyokota           #+#    #+#             */
/*   Updated: 2022/01/09 18:33:38 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	remove_brackets(char *str)
{
	char	c;

	while (*str)
	{
		if (*str == '\'' || *str == '"')
		{
			c = *str;
			ft_memmove(str, &str[1], ft_strlen(str));
			while (*str != c)
				++str;
			ft_memmove(str, &str[1], ft_strlen(str));
		}
		else if (*str)
			++str;
	}
}
