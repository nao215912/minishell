/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exit_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:31:48 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/03 17:31:49 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit_status.h"

char	*get_exit_status(void)
{
	return (exit_status(0, GETTER));
}
