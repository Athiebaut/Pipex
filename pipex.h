/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athiebau <athiebau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:47:15 by athiebau          #+#    #+#             */
/*   Updated: 2023/10/13 17:53:12 by athiebau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include "Libft/libft.h"

enum	error
{
	E_PIPE,
	E_FORK,
};

typedef struct s_pipex
{
	char	**path_env;
	char	**nom;
	int		fd[2];
}			t_pipex;
