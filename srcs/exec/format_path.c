/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyokota <nyokota@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:21:10 by nyokota           #+#    #+#             */
/*   Updated: 2022/01/14 18:06:16 by nyokota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "libft.h"

static void	isdir(char *path)
{
	struct stat	st;

	if (!stat(path, &st) && (st.st_mode & S_IFMT) == S_IFDIR)
	{
		ft_put_str_fd("minishell: ", STDERR_FILENO);
		ft_put_str_fd(path, STDERR_FILENO);
		ft_putendl_fd(": is a directory", STDERR_FILENO);
		exit(126);
	}
}

char	*format_path(char *cmd, char **path)
{
	char		*ret;
	char		*tmp;

	isdir(cmd);
	if (access(cmd, X_OK) == 0)
		return (cmd);
	tmp = ft_strjoin("/", cmd);
	while (path && *path)
	{
		ret = ft_strjoin(*path, tmp);
		if (access(ret, X_OK) == 0)
			return (free(tmp), ret);
		free(ret);
		++path;
	}
	ft_put_str_fd("minishell: ", STDERR_FILENO);
	ft_put_str_fd(cmd, STDERR_FILENO);
	if (ft_strchr(cmd, '/'))
		ft_putendl_fd(": No such file or directory", STDERR_FILENO);
	else
		ft_putendl_fd(": command not found", STDERR_FILENO);
	exit(127);
	return (NULL);
}
