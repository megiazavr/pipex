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

int     error_handler(int ac, char *av[], int *fd);
int     ft_is_space(unsigned char c);
int	    **allocate_memory(char *str, int i, int k, int start, int end);
t_arg	next_token(const char *str, int i);
int     count_words(const char *str);
char	word(char *str, int start, int end);

#endif