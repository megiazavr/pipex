/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <megiazar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 18:33:02 by megiazar          #+#    #+#             */
/*   Updated: 2025/12/05 22:54:06 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_absolute_path(char *str)
{
	if (ft_strchr(str, '/'))
	{
		if (access(str, X_OK) == 0)
			return (str);
	}
	return (NULL);
}

char	*are_you_path(char *env[])
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

char	**split_path(char *env[])
{
	char	*path;
	char	*copy_path;
	char	**parser;
	int		i;

	path = are_you_path(env);
	if (!path)
	{
		write(2, "PATH not found!\n", 10);
		return (NULL);
	}
	copy_path = ft_strdup(path);
	if (!copy_path)
		return (NULL);
	i = 0;
	while (copy_path[i])
	{
		if (copy_path[i] == ':')
			copy_path[i] = ' ';
		i++;
	}
	parser = split_cmd(copy_path, 0);
	free(copy_path);
	return (parser);
}

char	*cmd_path(char *cmd, char **env, int i)
{
	char	**path;
	char	*join;
	char	*full_path;

	if (!cmd)
		return (NULL);
	path = split_path(env);
	if (!path)
		return (NULL);
	while (path[i])
	{
		join = ft_strjoin(path[i], "/");
		full_path = ft_strjoin(join, cmd);
		free(join);
		if (access(full_path, X_OK) == 0)
		{
			free_arr(path);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free_arr(path);
	return (NULL);
}

char	*ft_strchr(char *s, char c)
{
	char	*pointer;
	int		i;

	i = 0;
	pointer = s;
	while (pointer[i])
	{
		if (pointer[i] == c)
			return (s);
		i++;
	}
	if (c == '\0')
		return (s);
	return (NULL);
}
