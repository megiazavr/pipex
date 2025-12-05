/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <megiazar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 18:23:19 by megiazar          #+#    #+#             */
/*   Updated: 2025/12/05 20:30:26 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	prepare_process(t_process *data)
{
	data->cmd1 = NULL;
	data->cmd2 = NULL;
	data->path = NULL;
	data->fd[0] = -1;
	data->fd[1] = -1;
	data->pipe_fd[0] = -1;
	data->pipe_fd[1] = -1;
}

void	free_all_process(t_process *data)
{
	if (data->cmd1)
		free_arr(data->cmd1);
	if (data->cmd2)
		free_arr(data->cmd2);
	if (data->path)
		free_arr(data->path);
	if (data->fd[0] != -1)
		close(data->fd[0]);
	if (data->fd[1] != -1)
		close(data->fd[1]);
}

int	main(int ac, char *av[], char *env[])
{
	t_process	data;

	if (!env || !env[0])
		return (write (2, "No environment!\n", 17), 1);
	if (ac != 5)
		return (write (2, "Too few args!\n", 14), 1);
	if (fd_handler(ac, av, data.fd) == 1)
		return (0);
	data.cmd1 = split_cmd(av[2], 0);
	data.cmd2 = split_cmd(av[3], 0);
	if (!data.cmd1 || !data.cmd1[0] || !data.cmd2 || !data.cmd2[0])
		return (free_all_process(&data), write(2, "Command parse error\n", 20));
	data.path = split_path(env);
	pipex(&data, env);
	free_all_process(&data);
	return (0);
}
