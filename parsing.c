#include "pipex.h"

int error_handler(int ac, char *av[], int *fd)
{
    int fd_in;
    int fd_out;

    if (ac > 5)
    {
        perror("Too much to handle!");
        return 1;
    }
    fd_out = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0664);
    if (fd_out == -1)
    {    
        perror("No permission to open the file outfile.txt");
        return 1;    
    }
    fd_in = open(av[1], O_CREAT | O_RDONLY);
    if (fd_in == -1)
    {
        perror("I can't open a infile.txt");
        return 1;
    }
    fd[0] = fd_in;
    fd[1] = fd_out;
    return (0);
}

// int ft_is_space(unsigned char c)
// {
//     return ((c >= 9 && c <= 13) || c == 32);
// }

// int ft_is_letter(unsigned char c)
// {
//     return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
// }

// int count_words(const char *str)
// {
//     int i;
//     int count_words;

//     count_words = 0;
//     i = 0;
//     if (!str)
//         return 0;
//     while (str[i] && ft_is_space(str[i]))
//         i++;
//     while(str[i])
//     {
//         count_words++;
//         while (str[i] && !ft_is_space(str[i]))
//             i++;
//         while (str[i] && ft_is_space(str[i]))
//             i++;
//     }
//     return (count_words);
// }

// char *word(const char *str)
// {
//     int i;
//     int start;
//     int end;
//     char word;
//     int len;

//     i = 0;
//     while (str[i])
//     {
//         while (str[i] && ft_is_space(str[i]))
//             i++;
//         start = i;
//         while ((str[i]) && !ft_is_space(str[i]))
//             i++;
//        i = end - 1;
//     }
//     word = end - start;
//     return (word);
// }

// char allocate_memory(const char *str)
// {
//     int i;
//     int start;
//     int end;
// char one_word
//     i = 0;
//     while (str[i])
//     {
//         one_word = end - start - 1;

//     }
//      = word(start, end);
//     char one_word = malloc(sizeof(char *) + 1);
//     while (str[i])
//     {

//     }
// }
// // snachala tokeni

// int find_path(char **env, char *way)
// {
//     t_process   point;
//     int i;

//     i = 0;

// }



int main(int ac, char *av[], char *env[])
{
    t_process point;

    if (!env[0])
        return (perror("Nothing created yet!"), 0);
    if (error_handler(ac, av, point.fd) == 1)
        return (0);
}