#include "pipex.h"

int fill_args(char **arr, char *str)
{
    t_arg   n;
    int i;
    int k;

    i = 0;
    k = 0;
    while (1)
    {
        n = next_token(str, i);
        if (!n.ok)
            break ;
        arr[k] = word(str, n.start, n.end);
        if (!arr[k])
            return (k);
        k++;
        i = n.next_i;
    }
    arr[k] = NULL;
    return (-1);
}

int ft_is_space(unsigned char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

void	free_arr(char **arr, int k)
{
	while (k > 0)
		free(arr[--k]);
	free(arr);
}

t_arg ft_quote(const char *str, int i)
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

t_arg ft_word(const char *str, int i)
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
