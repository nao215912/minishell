/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:39:10 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/02 18:40:03 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "parser.h"

bool	is_builtin(t_node *args)
{
	if (args)
		return (msh_get_builtin(args->str));
	return (false);
}
