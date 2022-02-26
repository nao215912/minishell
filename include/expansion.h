/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:31:06 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/23 18:37:02 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

# include <stdlib.h>
# include <stdbool.h>

typedef struct s_env	t_env;

char	*expansion(t_env *env, char *line);
char	*expansion_sq(char *str, size_t *idx);
char	*expansion_dq(t_env *env, char *str, size_t *idx);
char	*expansion_sp(t_env *env, char *str, size_t *idx);
char	*expand_env(t_env *env, char *str);
bool	is_env_ch(int c);

#endif /* EXPANSION_H */
