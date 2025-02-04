#include "../../inc/minishell.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = (unsigned char *)s;
	while (i < n)
	{
		*p = (unsigned char)c;
		p++;
		i++;
	}
	return (s);
}

int ft_isspace(int c)
{
    return (c == '\t' || c == '\r' || c == '\n' || c == '\v' || c == '\f' || c == ' ');
}

int	main(int argc, char **argv)
{
	t_tok	*list;
	t_cmd	*tree;
	t_cmd	*t_temp;
	int		i;
	
	if (argc != 2)
		return (1);
	list = lexer(argv[1]);
	if (!list)
		printf("Failed to tokenize\n");
	tree = parser(list);
	if (!tree)
	{
		printf("Parsing failed\n");
		return (1);
	}
	t_temp = tree;
	while (t_temp)
	{
		i = 0;
		printf("Cmd Node:\n");
		printf("Args:");
		while (tree->args[i] != NULL)
		{
			printf(" %s", tree->args[i]);
			i++;
		}
		printf("\nIN_FD: %d\n", tree->in_fd);
		printf("OUT_FD: %d\n", tree->out_fd);
		t_temp = t_temp->next;
	}
	return (0);
}
