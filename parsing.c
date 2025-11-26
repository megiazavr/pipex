#include "pipex.h"

int error_handler(int ac, char *av[], int *fd)
{
	int fd_in;
	int fd_out;

	if (ac != 5)
	{
		printf("Too much to handle!");
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

int ft_is_space(unsigned char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static void	free_arr(char **arr, int k)
{
	while (k > 0)
		free(arr[--k]);
	free(arr);
}

static t_arg ft_quote(const char *str, int i)
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

static t_arg ft_word(const char *str, int i)
{
	t_arg	a;

	a.ok = 1;
	a.start = i;
	while (str[i] && !ft_is_space((unsigned char)str[i]) 
															&& str[i] != '"')
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


int count_words(const char *str)
{
	int	i;
	int 		count_words;
	t_arg args;

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
	arr = (char **)malloc(len + 1);
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

int	**allocate_memory(char *str, int i, int k, int start, int end)
{
	int	j;
	char	**arr;
	t_arg	n;

	if (!str)
		reurn (NULL);
	j = count_words(str);
	arr = (char**)malloc(sizeof(char**) * (j + 1));
	if (!arr)
		return (NULL);
	i = 0;
	k = 0;
	while (1)
	{
		n = next_token(str, i);
		if (!n.ok)
			break ;
		arr[k] = word(str, n.start, n.end);
		if (!arr[k])
			return (free_arr(arr, k), NULL);
		k++;
		i = n.next_i;
	}
	arr[k] = '\0';
	return (arr);
}