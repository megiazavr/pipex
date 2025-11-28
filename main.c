#include "pipex.h"

int main(int ac, char *av[], char *envp[])
{
    int     fd[2];

    if (!envp || !envp[0])
        return (perror("No env"), 1);
    if (error_handler(ac, av, fd))
        return (1);

    return (0);
}
