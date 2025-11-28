#include "pipex.h"

int error_handler(int ac, char *av[], int *fd)
{
	int fd_in;
	int fd_out;

	if (ac != 5)
	{
		printf("Cant hande this amount of vars!");
		return (1);
	}
	fd_out = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_out == -1)
	{    
		perror("No permission to open the file outfile.txt");
		return (1);    
	}
	fd_in = open(av[1], O_RDONLY);
	if (fd_in == -1)
	{
		perror("I can't open a infile.txt");
		close(fd_out);
		return (1);
	}
	fd[0] = fd_in;
	fd[1] = fd_out;
	return (0);
}

t_arg	next_token(const char *str, int i)
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

int count_words(const char *str)
{
	int		i;
	int 	count_words;
	t_arg 	args;

	if (!str)
		return 0;
	count_words = 0;
	i = 0;
	while (str[i] && ft_is_space((unsigned char)str[i]))
		i++;
	while (1)
	{
		args = next_token(str, i);
		if (!args.ok)
			break ;
		count_words++;
		i = args.next_i;
	}
	return (count_words);
}

char	*word(char *str, int start, int end)
{
	int 	i;
	int 	len;
	char 	*arr;

	len = end - start;
	arr = malloc(sizeof(char *) * (len + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (start < end)
	{
		arr[i] = str[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}


char	**allocate_memory(char *str)
{
	int		words;
	char	**arr;
	int		err;

	if (!str)
		return (NULL);
	words = count_words(str);
	arr = malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	err = fill_args(arr, str);
	if (err >= 0)
	{
		free_arr(arr, err);
		return (NULL);
	}
	return (arr);
}
