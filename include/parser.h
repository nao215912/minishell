/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:35:32 by nyokota           #+#    #+#             */
/*   Updated: 2022/01/10 21:51:50 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdlib.h>

typedef struct s_token		t_token;
typedef struct s_node		t_node;
typedef struct s_executor	t_executor;

typedef enum e_kind
{
	TK_CMD,
	TK_RI,
	TK_DRI,
	TK_RO,
	TK_DRO
}t_kind;

typedef struct s_node
{
	t_kind				kind;
	char				*str;
	int					fd;
	int					here_doc_fd;
	int					dup_fd;
	t_node				*next;
}t_node;

void		node_add_back(t_node **lst, t_node *add);
void		node_clear(t_node *head);
t_executor	*parser(t_token *token);

#endif /* PARSER_H */
