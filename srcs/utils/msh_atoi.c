/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:31:03 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/03 20:31:03 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	msh_atoi(char *str, bool *is_over_flow)
{
	int	ret;

	ret = 0;
	*is_over_flow = false;
	while (is_number(*str))
	{
		if ((ret * 10 + (*str - '0')) / 10 != ret)
		{
			*is_over_flow = true;
			return (ret);
		}
		ret = ret * 10 + (*str++ - '0');
	}
	return (ret);
}
