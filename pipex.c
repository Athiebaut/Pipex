/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:47:26 by athiebau          #+#    #+#             */
/*   Updated: 2023/10/17 17:17:25 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit(int signal)
{
	exit(-1);
}

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
	free(path);
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
		
	}
	
	
		
}

void	ft_child_begin(t_pipex *info, char **argv, char **env)
{
	int	fd;
	
	fd = open(argv[1], O_RDONLY);
	dup2(fd, 0);
	dup2(info->fd[1], 1);
	close(info->fd[0]);
	close(info->fd[1]);
	close(fd); 
	ft_exec(info, argv[1], env);
}

void	ft_child_end(t_pipex *info, char **argv, char **env)
{
	int	fd;
	
	fd = open(argv[4], O_WRONLY);
	dup2(fd, 1);
	dup2(info->fd[0], 0);
	close(info->fd[1]);
	ft_exec(info, argv[4], env);
}

int main(int argc, char **argv, char **env)
{
	t_pipex	info;
	pid_t	pid;
	
	ft_bzero(&info, sizeof(t_pipex));
	/*if (argc != 5)
		exit(1);*/
	ft_parse(&info, env);
	if (pipe(info.fd) == -1)
		ft_exit(E_PIPE);
	pid = fork();
	if (pid == -1)
		ft_exit(E_FORK);
	if (pid == 0)
		ft_child_begin(&info, argv, env);
	if (pid != 0)
	{
		pid = fork();
		if (pid == -1)
			ft_exit(E_FORK);
		if (pid == 0)
			ft_child_end(&info, argv, env);
	}
	exit(0);
}
