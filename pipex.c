/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <megiazar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:43:06 by megiazar          #+#    #+#             */
/*   Updated: 2025/12/05 22:53:39 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fd(t_process *data)
{
	close(data->pipe_fd[0]);
	close(data->pipe_fd[1]);
	close(data->fd[0]);
	close(data->fd[1]);
}

void	first_child(t_process *data, char **env)
{
	char	*path;

	if (dup2(data->fd[0], STDIN_FILENO) == -1)
		exit(1);
	if (dup2(data->pipe_fd[1], STDOUT_FILENO) == -1)
		exit(1);
	close_fd(data);
	path = find_absolute_path(data->cmd1[0]);
	if (!path)
		path = cmd_path(data->cmd1[0], env, 0);
	if (!path)
	{
		write(2, data->cmd1[0], ft_strlen(data->cmd1[0]));
		write(2, ": Command not found\n", 20);
		free_all_process(data);
		exit (1);
	}
	execve(path, data->cmd1, env);
	perror("If you see this, execve doesnt work\n");
	free(path);
	exit(1);
}

void	second_child(t_process *data, char **env)
{
	char	*path;

	if (dup2(data->pipe_fd[0], STDIN_FILENO) == -1)
		exit(1);
	if (dup2(data->fd[1], STDOUT_FILENO) == -1)
		exit(1);
	close_fd(data);
	path = find_absolute_path(data->cmd2[0]);
	if (!path)
		path = cmd_path(data->cmd2[0], env, 0);
	if (!path)
	{
		write(2, data->cmd2[0], ft_strlen(data->cmd2[0]));
		write(2, ": Command not found\n", 20);
		free_all_process(data);
		exit (1);
	}
	execve(path, data->cmd2, env);
	perror("For cmd2; If you see this, execve doesnt work\n");
	free(path);
	exit(1);
}

void	pipex(t_process *data, char **env)
{
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	if (pipe(data->pipe_fd) == -1)
		return (perror("pipe"), (void)0);
	pid1 = fork();
	if (pid1 == -1)
		return (perror("fork"), (void)0);
	if (pid1 == 0)
		first_child(data, env);
	pid2 = fork();
	if (pid2 == -1)
		return (perror("fork"), (void)0);
	if (pid2 == 0)
		second_child(data, env);
	close_fd(data);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
}
