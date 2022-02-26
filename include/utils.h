/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:36:30 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/23 18:11:43 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>

void	skip_space(char *str, size_t *idx);
void	skip_until_ch(char *str, size_t *idx, int c);
bool	is_space(int c);
bool	is_number(int c);
bool	is_number_string(char *str);
int		msh_atoi(char *str, bool *is_over_flow);
char	*substr(char *start, char *end);
void	*xmalloc(size_t size);
int		xdup(int oldfd);
void	xdup2(int oldfd, int newfd);
void	xclose(int fd);
void	xpipe(int pipefd[2]);
pid_t	xwaitpid(pid_t pid, int *wstatus, int mode);
pid_t	xfork(void);
void	clear_string_array(char **arr);
void	xperror(char *str);

#endif