# ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct s_process
{
    char    **env;
    char    **path;
    char    **cmd1;
    char    **cmd2;
    int     fd[2];
} t_process;

typedef struct s_arg
{
    int ok;
    int start;
    int end;
    int next_i;
}   t_arg;

void	free_arr(char **arr, int k);

int     error_handler(int ac, char *av[], int *fd);
int     ft_is_space(unsigned char c);
t_arg ft_quote(const char *str, int i);
t_arg ft_word(const char *str, int i);
char    **allocate_memory(char *str);
char	*word(char *str, int start, int end);
int     count_words(const char *str);
t_arg	next_token(const char *str, int i);
int     fill_args(char **arr, char *str);

#endif