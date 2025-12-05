/* ************************************************************************** */
/*	                                                                          */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <megiazar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 18:23:40 by megiazar          #+#    #+#             */
/*   Updated: 2025/12/05 17:06:54 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>

typedef struct s_process
{
	char	**env;
	char	**path;
	char	**cmd1;
	char	**cmd2;
	int		fd[2];
	int		pipe_fd[2];
}	t_process;

typedef struct s_arg
{
	int	ok;
	int	start;
	int	end;
	int	next_i;
}	t_arg;

void	free_arr(char **arr);
void	prepare_process(t_process *data);
void	free_all_process(t_process *data);

t_arg	next_token(char *str, int i);

int		fd_handler(int ac, char *av[], int *fd);
int		ft_is_space(unsigned char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(char *s);
int		count_words(char *str);

void	*ft_memcpy(void *dest, void *src, size_t n);
void	close_fd(t_process *data);
void	first_child(t_process *data, char **env);
void	second_child(t_process *data, char **env);
void	pipex(t_process *data, char **env);

char	*ft_strdup(char *s);
char	**split_cmd(char *str, int k);
char	*word(char *str, int start, int end);
char	*are_you_path(char *env[]);
char	**split_path(char *env[]);
char	*ft_strjoin(char *s1, char *s2);
char	*cmd_path(char *cmd, char **env, int i);
char	*ft_strchr(char *s, char c);
char	*find_absolute_path(char *str);

#endif