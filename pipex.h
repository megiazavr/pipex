# ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_process
{
    char **env;
    char **path;
    int fd[2];
    char **cmd1;
    char **cmd2;
} t_process;

int error_handler(int ac, char *av[], int *fd);
int ft_is_space(unsigned char c);


#endif