/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:30:07 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/03 20:43:01 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <stddef.h>
# include <stdbool.h>

typedef struct s_executor	t_executor;
typedef struct s_node		t_node;
typedef struct s_env		t_env;

typedef enum e_builtin_idx
{
	BI_CD,
	BI_ECHO,
	BI_ENV,
	BI_EXIT,
	BI_EXPORT,
	BI_PWD,
	BI_UNSET,
	BI_OTHER
}t_builtin_idx;

typedef struct s_builtin
{
	char	*name;
	int		(*func)(t_node	*args, t_env	**envp);
}t_builtin;

const t_builtin	*msh_get_builtin(char *command);
int				msh_bi_unset(t_node *args, t_env **envp);
int				msh_bi_pwd(t_node *args, t_env **envp);
int				msh_bi_export(t_node *args, t_env **envp);
int				msh_bi_exit(t_node *args, t_env **envp);
int				msh_bi_env(t_node *args, t_env **envp);
int				msh_bi_echo(t_node *args, t_env **envp);
int				msh_bi_cd(t_node *args, t_env **envp);
bool			is_builtin(t_node *args);
int				exec_builtin(t_executor *executor, t_env **envp);

#endif /* BUILTIN_H */
