/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_sq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:32:27 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/03 17:32:27 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*expansion_sq(char *str, size_t *idx)
{
	char	*start;

	start = &str[*idx];
	skip_until_ch(str, idx, '\'');
	return (substr(start, &str[*idx]));
}
