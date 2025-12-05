/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <megiazar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 18:23:32 by megiazar          #+#    #+#             */
/*   Updated: 2025/12/04 19:00:57 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_arg	ft_quote(char *str, int i)
{
	t_arg	a;

	a.ok = 1;
	i++;
	a.start = i;
	while (str[i] && str[i] != '"')
		i++;
	a.end = i;
	if (str[i] == '"')
		i++;
	a.next_i = i;
	return (a);
}

static t_arg	ft_word(char *str, int i)
{
	t_arg	a;

	a.ok = 1;
	a.start = i;
	while (str[i] && !ft_is_space((unsigned char)str[i]) && str[i] != '"')
		i++;
	a.end = i;
	a.next_i = i;
	return (a);
}

t_arg	next_token(char *str, int i)
{
	t_arg	arg;

	arg.ok = 0;
	arg.start = 0;
	arg.end = 0;
	arg.next_i = i;
	if (!str)
		return (arg);
	while (str[i] && ft_is_space((unsigned char)str[i]))
		i++;
	if (!str[i])
		return (arg);
	if (str[i] == '"')
		return (ft_quote(str, i));
	return (ft_word(str, i));
}

int	count_words(char *str)
{
	int		i;
	int		count;
	t_arg	token;

	if (!str)
		return (0);
	count = 0;
	i = 0;
	while (str[i] && ft_is_space((unsigned char)str[i]))
		i++;
	while (1)
	{
		token = next_token(str, i);
		if (!token.ok)
			break ;
		count++;
		i = token.next_i;
	}
	return (count);
}

char	*word(char *str, int start, int end)
{
	int		len;
	int		i;
	char	*res;

	len = end - start;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = str[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
