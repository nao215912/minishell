/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:31:29 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/03 21:16:42 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <stdbool.h>
# include <stdlib.h>
# define SYNTAX_ERROR "minishell: syntax error"
# define BAD_FD "minishell: file descriptor out of range: Bad file descriptor"

typedef struct s_token		t_token;
typedef struct s_node		t_node;
typedef struct s_executor	t_executor;
typedef enum e_kind			t_kind;

typedef enum e_op_idx
{
	OP_DRI,
	OP_RI,
	OP_DRO,
	OP_RO,
	OP_PIPE,
	OP_OTHER
}t_op_idx;

typedef struct s_token
{
	t_op_idx	operator;
	char		*str;
	bool		(*to_node)(t_token * token, t_executor * executor);
	t_token		*next;
	t_token		*prev;
}t_token;

t_token	*lexer(char *line);
bool	is_brackets_closed(char *line);
void	remove_brackets(char *str);
void	token_clear(t_token *head);
bool (*get_op_func(t_op_idx op_idx))(t_token * token, t_executor * executor);
bool	op_to_node(t_token *token, t_node *node, t_kind kind, int fd);
bool	op_ri_to_node(t_token *token, t_executor *executor);
bool	op_dri_to_node(t_token *token, t_executor *executor);
bool	op_ro_to_node(t_token *token, t_executor *executor);
bool	op_dro_to_node(t_token *token, t_executor *executor);
bool	op_pipe_to_node(t_token *token, t_executor *executor);
bool	op_other_to_node(t_token *token, t_executor *executor);

#endif /* LEXER_H */
