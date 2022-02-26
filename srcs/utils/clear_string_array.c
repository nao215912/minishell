/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_string_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:30:45 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/03 20:30:45 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	clear_string_array(char **arr)
{
	size_t	idx;

	if (!arr)
		return ;
	idx = 0;
	while (arr[idx])
		free(arr[idx++]);
	free(arr);
}
