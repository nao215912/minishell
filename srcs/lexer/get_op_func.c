/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:33:53 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/03 17:58:42 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "exec.h"

bool (*get_op_func(t_op_idx op_idx))(t_token * token, t_executor * executor){
static bool (*funcs[])(t_token * token, t_executor * executor) = {
op_dri_to_node,
op_ri_to_node,
op_dro_to_node,
op_ro_to_node,
op_pipe_to_node,
op_other_to_node};

return (funcs[op_idx]);
}
