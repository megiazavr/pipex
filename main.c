#include "pipex.h"

int main(int ac, char *av[], char *env[])
{
	t_process point;

	if (ac != 5)
		return 1;
	if (!env[0])
		return (perror("Nothing created yet!"), 0);
	if (error_handler(ac, av, point.fd) == 1)
		return (0);
	char cmd1 = allocate_memory(av[2]);
	char cmd2 = allocate_memory(av[3]);
}