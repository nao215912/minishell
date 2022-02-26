/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:34:24 by nyokota           #+#    #+#             */
/*   Updated: 2021/12/02 18:35:23 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_put_str_fd(char *str, int fd);
void	ft_putendl_fd(char *str, int fd);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	**ft_split(char *s, char c);
char	*ft_charskip(const char *str, char skip);
bool	ft_isdigitstr(char *str);
int		ft_isdigit(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_spaceskip(const char *str);
int		ft_atoi(const char *str);

#endif