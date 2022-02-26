/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:37:58 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/03 20:47:16 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "parser.h"
#include "builtin.h"
#include "env.h"

int	exec_builtin(t_executor *executor, t_env **envp)
{
	return (msh_get_builtin(executor->command->str)->\
	func(executor->command->next, envp));
}
