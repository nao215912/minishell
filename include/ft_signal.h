/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:35:57 by nyokota           #+#    #+#             */
/*   Updated: 2022/01/14 21:18:59 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIGNAL_H
# define FT_SIGNAL_H

# include "ft_signal.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/errno.h>
# include <unistd.h>
# include <readline/readline.h>

void	ft_heredoc_sig_hundler(void);
void	ft_child_sig_hundler(void);
void	ft_parent_sig_hundler(void (*func)(int sig));
void	ft_parent_signal_sigint(int sig);

#endif
