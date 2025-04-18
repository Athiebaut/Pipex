/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:59:17 by athiebau          #+#    #+#             */
/*   Updated: 2025/04/18 21:39:25 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief Parses the environment variables to extract the PATH variable
 *        and splits it into an array of paths.
 *
 * @param info A pointer to the t_pipex structure where the parsed PATH
 *             environment variable will be stored.
 * @param env  The environment variables array.
 *
 * @details This function iterates through the provided environment variables
 *          to find the "PATH=" variable. Once found, it extracts the value
 *          (excluding the "PATH=" prefix) and splits it into an array of
 *          paths using ':' as the delimiter. The resulting array is stored
 *          in the `path_env` field of the `t_pipex` structure. If the PATH
 *          variable is not found, the function exits with a status of -1.
 */
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

/**
 * @brief Retrieves the full executable path for a given command.
 *
 * This function checks if the command provided in `info->cmd[0]` is directly
 * accessible (exists and is executable). If so, it returns the command itself.
 * Otherwise, it iterates through the directories listed in `info->path_env`,
 * appending the command name to each directory path, and checks if the resulting
 * path is accessible. If a valid path is found, it is returned. If no valid path
 * is found, the function returns NULL.
 *
 * @param info A pointer to a `t_pipex` structure containing the command and
 *             environment path information.
 * 
 * @return A string containing the full path to the executable if found, or NULL
 *         if the command cannot be located in the specified paths.
 *
 * @note The caller is responsible for freeing the returned path if it is not
 *       `info->cmd[0]`.
 */
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

/**
 * ft_exec - Executes a command in a child process.
 *
 * @info: A pointer to a t_pipex structure containing necessary information
 *        for the execution process.
 * @cmd: A string representing the command to be executed.
 * @env: An array of strings representing the environment variables.
 *
 * This function splits the given command string into an array of arguments,
 * retrieves the full path of the command, and executes it using the execve
 * system call. If any step fails, it handles the error by printing an
 * appropriate message and exiting the program with a specific error code.
 *
 * Error Handling:
 * - If the command string cannot be split, the function exits with E_SPLIT.
 * - If the command path cannot be resolved, the function exits with E_PATH.
 * - If the execve system call fails, the function exits with E_EXEC.
 */
void	ft_exec(t_pipex *info, char *cmd, char **env)
{	

	char *c = "oui";
	info->cmd = ft_split(cmd, ' ');
	if (!info->cmd)
		ft_exit(E_SPLIT, info);	
	info->path_cmd = ft_get_the_path(info);
	if (!info->path_cmd)
	{
		ft_putstr_fd("pipex: ", 2);
		(perror(cmd), ft_exit(E_PATH, info));
	}
	if (execve(info->path_cmd, info->cmd, env) == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		perror(cmd);
		ft_exit(E_EXEC, info);
	}
}
