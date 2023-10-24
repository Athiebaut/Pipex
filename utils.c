/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:59:17 by athiebau          #+#    #+#             */
/*   Updated: 2023/10/24 14:45:52 by athiebau         ###   ########.fr       */
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
		path = ft_strjoin(info->path_env[i], "/");
		path2 = ft_strjoin(path, info->cmd[0]);
		free(path);
		if (access(path2, F_OK | X_OK) == 0)
			return (path2);
		free(path2);	
	}
	return (NULL);
}

void	ft_exec(t_pipex *info, char *cmd, char **env)
{	
	info->cmd = ft_split(cmd, ' ');
	if (!info->cmd)
		ft_exit(E_SPLIT, info);	
	info->path_cmd = ft_get_the_path(info);
	if (!info->path_cmd)
		ft_exit(E_PATH, info);
	if (execve(info->path_cmd, info->cmd, env) == -1)
	{
		ft_putstr_fd("Pipex: command not found: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_exit(E_EXEC, info);
	}
}
