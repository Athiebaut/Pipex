/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:47:26 by athiebau          #+#    #+#             */
/*   Updated: 2023/10/24 15:48:41 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit(int signal, t_pipex *info)
{
	int	i;

	i = -1;
	if (info->path_env)
	{
		while(info->path_env[++i])
			free(info->path_env[i]);
		free(info->path_env);
	}
	i = -1;
	if (E_PATH || E_EXEC || END)
	{
		if (info->cmd)
		{
			while(info->cmd[++i])
				free(info->cmd[i]);
			free(info->cmd);
		}
		i = -1;
		if (E_EXEC || END)
		{
			if(info->path_cmd)
				free(info->path_cmd);
		}
	}
	if (signal != END)
		ft_putstr_fd("Error\n", 2);
	exit(-1);
}

void	ft_child_begin(t_pipex *info, char **argv, char **env)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		(perror(argv[1]), ft_exit(E_OPEN, info)); //close fd pipe + fd
	if (dup2(fd, 0) == -1)
		ft_exit(E_DUP, info); //close fd pipe + fd
	if (dup2(info->fd[1], 1) == -1)
		ft_exit(E_DUP, info); //close fd pipe + fd
	if (close(info->fd[0]) == -1)
		ft_exit(E_CLOSE, info); //close 1 des fd pipe + fd
	if (close(info->fd[1]) == -1)
		ft_exit(E_CLOSE, info);//close  fd
	if (close(fd) == -1)
		ft_exit(E_CLOSE, info);
	ft_exec(info, argv[2], env);
}

void	ft_child_end(t_pipex *info, char **argv, char **env)
{
	int	fd;

	fd = open(argv[4], O_WRONLY | O_CREAT); //O_TRUNC
	if (fd == -1)
	{
		perror(argv[4]);		
		ft_exit(E_OPEN, info); //close fd pipe + fd
	}
	if (dup2(fd, 1) == -1)
		ft_exit(E_DUP, info); //close fd pipe + fd
	if (dup2(info->fd[0], 0) == -1)
		ft_exit(E_DUP, info); //close fd pipe + fd
	if (close(info->fd[0]) == -1)
		ft_exit(E_CLOSE, info);  //close 1 des fd pipe + fd
	if (close(info->fd[1]) == -1)
		ft_exit(E_CLOSE, info);//close  fd
	if (close(fd) == -1)
		ft_exit(E_CLOSE, info);
	ft_exec(info, argv[3], env);
}

int main(int argc, char **argv, char **env)
{
	t_pipex	info;
	pid_t	pid;
	
	ft_bzero(&info, sizeof(t_pipex));
	if (argc != 5)
		exit(-1);
	ft_parse(&info, env);
	if (!info.path_env)
		exit(-1);
	if (pipe(info.fd) == -1)
		ft_exit(E_PIPE, &info);
	pid = fork();
	if (pid == -1)
		ft_exit(E_FORK, &info);
	if (pid == 0)
		ft_child_begin(&info, argv, env);
	if (pid != 0)
	{
		pid = fork();
		if (pid == -1)
			ft_exit(E_FORK, &info);
		if (pid == 0)
			ft_child_end(&info, argv, env);
		if (pid != 0)
		{
			close(info.fd[0]);
			close(info.fd[1]);
		}
	}
	while(wait(NULL) > 0);
	ft_exit(END, &info);
}
