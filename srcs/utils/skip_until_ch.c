/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_until_ch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:31:11 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/03 20:31:11 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	skip_until_ch(char *str, size_t *idx, int c)
{
	++*idx;
	while (str[*idx] && str[*idx] != c)
		++*idx;
	if (str[*idx] == c)
		++*idx;
}
