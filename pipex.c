/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:47:26 by athiebau          #+#    #+#             */
/*   Updated: 2023/10/13 17:54:38 by athiebau         ###   ########.fr       */
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

int	ft_child(t_pipex, char **argv)
{
	
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
		ft_child(&info, argv);
	ft_parent(&info, argv);
	return (0);
}