/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:30:53 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/02 18:30:53 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_STATUS_H
# define EXIT_STATUS_H

# include <stddef.h>

typedef enum e_func_type
{
	SETTER,
	GETTER,
}t_func_type;

char	*exit_status(int n, t_func_type func_type);
char	*get_exit_status(void);
void	set_exit_status(int n);

#endif /* EXIT_STATUS_H */