/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alix <alix@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:47:26 by athiebau          #+#    #+#             */
/*   Updated: 2025/04/18 21:38:40 by alix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/**
 * @brief Frees allocated memory and exits the program with an error code.
 * 
 * This function is designed to handle cleanup and exit the program when an
 * error occurs. It frees memory allocated for the `path_env`, `cmd`, and
 * `path_cmd` fields of the `t_pipex` structure, depending on the error
 * conditions specified by the macros `E_PATH`, `E_EXEC`, and `END`.
 * 
 * @param signal The signal or error code triggering the exit.
 * @param info A pointer to the `t_pipex` structure containing allocated
 *             resources to be freed.
 * 
 * @note The function calls `exit(-1)` to terminate the program after cleanup.
 *       Ensure that all necessary resources are properly freed before calling
 *       this function.
 */
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
	exit(-1);
}

/**
 * @brief Executes the first child process in a pipeline.
 *
 * This function sets up the input and output file descriptors for the first 
 * child process in a pipeline. It opens the input file specified in `argv[1]`, 
 * redirects the standard input to this file, and redirects the standard output 
 * to the write end of the pipe. It then closes unnecessary file descriptors 
 * and executes the command specified in `argv[2]` using the provided environment.
 *
 * @param info A pointer to the `t_pipex` structure containing pipe file descriptors.
 * @param argv The command-line arguments, where `argv[1]` is the input file 
 *             and `argv[2]` is the command to execute.
 * @param env The environment variables to be passed to the executed command.
 *
 * @note If any system call (e.g., `open`, `dup2`, `close`) fails, the function 
 *       will call `ft_exit` to handle the error and terminate the program.
 *
 * Error Handling:
 * - If the input file cannot be opened, an error message is printed using `perror`, 
 *   and the program exits with the appropriate error code.
 * - If any file descriptor duplication (`dup2`) or closure (`close`) fails, 
 *   the program exits with the appropriate error code.
 */
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

/**
 * ft_child_end - Handles the child process's end of a pipe in a pipeline.
 *
 * @info: A pointer to the t_pipex structure containing pipe and process information.
 * @argv: The command-line arguments array.
 * @env: The environment variables array.
 *
 * This function performs the following steps:
 * 1. Opens the output file specified by argv[4] with write and create permissions.
 *    If the file cannot be opened, it prints an error message and exits using ft_exit.
 * 2. Redirects the file descriptor for the output file to standard output (fd 1) using dup2.
 *    If dup2 fails, it exits using ft_exit.
 * 3. Redirects the read end of the pipe (info->fd[0]) to standard input (fd 0) using dup2.
 *    If dup2 fails, it exits using ft_exit.
 * 4. Closes the read and write ends of the pipe (info->fd[0] and info->fd[1]).
 *    If closing any of these fails, it exits using ft_exit.
 * 5. Closes the file descriptor for the output file.
 *    If closing it fails, it exits using ft_exit.
 * 6. Executes the command specified by argv[3] using ft_exec, passing the environment variables.
 *
 * Error handling is performed at each step to ensure proper resource cleanup
 * and program termination in case of failure.
 */
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

/**
 * @file pipex.c
 * @brief Implementation of a simple pipex program that simulates the behavior of a shell pipeline.
 *
 * This program takes four arguments and executes two commands in a pipeline, 
 * where the output of the first command is passed as input to the second command.
 *
 * @details
 * - The program initializes a `t_pipex` structure to store necessary information.
 * - It validates the number of arguments and parses the environment variables.
 * - Two child processes are created using `fork()`:
 *   - The first child process executes the first command.
 *   - The second child process executes the second command.
 * - A pipe is used to connect the output of the first command to the input of the second command.
 * - The parent process waits for both child processes to complete before exiting.
 *
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line arguments.
 * @param env The array of environment variables.
 *
 * @return This program does not return a value. It exits with a status code.
 *
 * @note
 * - If any error occurs (e.g., pipe creation, forking, or missing environment variables), 
 *   the program exits with an appropriate error code.
 * - The `ft_exit` function is used to handle cleanup and exit the program gracefully.
 */
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
