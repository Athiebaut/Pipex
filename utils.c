/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:59:17 by athiebau          #+#    #+#             */
/*   Updated: 2023/10/23 17:16:17 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_parse(t_pipex *info, char **env)
{
	char	*path;
	int	i;

	i = -1;
	path = NULL;
	while(env[++i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			path = env[i];
	}
	if (!path)
		exit(-1);
	info->path_env = ft_split(path + 5, ':');
}

char	*ft_get_the_path(t_pipex *info)
{
	char	*path;
	char	*path2;
	int	i;

	i = -1;
	if (access(info->cmd[0], F_OK | X_OK) == 0)
		return (info->cmd[0]);
	while(info->path_env[++i])
	{
		path = ft_strjoin(info->path_env[i], '/');
		path2 = ft_strjoin(path, info->cmd[0]);
		free(path);
		if (access(path2, F_OK | X_OK) == 0)
			return (path2);
		free(path2);	
	}
	return (NULL);
}

void	ft_exec(t_pipex *info, char *argv, char **env)
{
	char	*path;
	
	info->cmd = ft_split(argv, ' ');
	path = ft_get_the_path(info);
	if (path == NULL)
		ft_exit(E_PATH);
	if (execve(path, argv, env) == -1)
	{
		ft_putstr_fd("Pipex: command not found: ", 2);
		ft_putstr_fd(argv, 2);
		exit(0);
	}
}