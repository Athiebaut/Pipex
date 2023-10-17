/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:47:15 by athiebau          #+#    #+#             */
/*   Updated: 2023/10/17 16:36:44 by athiebau         ###   ########.fr       */
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
