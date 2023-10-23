/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:47:15 by athiebau          #+#    #+#             */
/*   Updated: 2023/10/23 17:06:44 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include "Libft/libft.h"

enum	error
{
	E_PIPE,
	E_FORK,
	E_OPEN,
	E_DUP,
	E_CLOSE,
	E_ACCESS,
	E_PATH,
	E_EXEC,
};

typedef struct s_pipex
{
	char	**path_env;
	char	**cmd;
	int		fd[2];
}			t_pipex;

void	ft_parse(t_pipex *info, char **env);
char	*ft_get_the_path(t_pipex *info);
void	ft_exec(t_pipex *info, char *argv, char **env);
void	ft_exit(int signal, t_pipex *info);
