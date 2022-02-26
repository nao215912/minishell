/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:31:33 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/03 18:10:29 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit_status.h"

static void	set_number_string(char *number_string, int n)
{
	int	digit;

	if (n < 0)
	{
		*number_string++ = '-';
		n *= -1;
	}
	digit = 1;
	while (n / digit > 10)
		digit *= 10;
	while (digit)
	{
		*number_string++ = '0' + ((n / digit) % 10);
		digit /= 10;
	}
	*number_string = '\0';
}

char	*exit_status(int n, t_func_type func_type)
{
	static char	number_string[12];

	if (func_type == GETTER)
		return (number_string);
	else if (func_type == SETTER)
		set_number_string(number_string, n);
	return (NULL);
}
