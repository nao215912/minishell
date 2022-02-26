/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:30:11 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/02 18:30:12 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include <stdlib.h>

typedef struct s_env	t_env;

struct s_env
{
	char	*key;
	char	*value;
	size_t	keylen;
	t_env	*next;
};

t_env	*init_env(char **envp);
char	*get_env(t_env *envp, char *key);
void	add_env(t_env **envp, t_env *add);
void	del_env(t_env **envp, char *key);
t_env	*new_env(char *key, char *value);
void	clear_env(t_env *head);

#endif