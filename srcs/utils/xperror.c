/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xperror.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 18:29:30 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/23 18:29:42 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <errno.h>

void	xperror(char *str)
{
	printf("minishell: %s: %s\n", str, strerror(errno));
}
