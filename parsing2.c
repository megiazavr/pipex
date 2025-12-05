/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <megiazar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 18:46:21 by megiazar          #+#    #+#             */
/*   Updated: 2025/12/05 22:39:14 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_is_space(unsigned char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

void	free_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	fd_handler(int ac, char *av[], int *fd)
{
	int	fd_in;
	int	fd_out;

	fd_out = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_out == -1)
	{
		perror(av[ac - 1]);
		return (1);
	}
	fd_in = open(av[1], O_RDONLY);
	if (fd_in == -1)
	{
		perror(av[1]);
		close(fd_out);
		return (1);
	}
	fd[0] = fd_in;
	fd[1] = fd_out;
	return (0);
}

char	**split_cmd(char *str, int k)
{
	int		i;
	int		words;
	char	**arr;
	t_arg	n;

	if (!str)
		return (NULL);
	words = count_words(str);
	arr = (char **)malloc(sizeof (char *) * (words + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (1)
	{
		n = next_token(str, i);
		if (!n.ok)
			break ;
		arr[k] = word(str, n.start, n.end);
		if (!arr[k])
			return (free_arr(arr), NULL);
		k++;
		i = n.next_i;
	}
	arr[k] = 0;
	return (arr);
}
