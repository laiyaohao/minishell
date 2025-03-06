#include "../../inc/minishell.h"

char	*heredoc_expand(char *s)
{
	char	*res;

	res = ft_strdup("");
	if (!res)
		return (NULL);
	while (s && *s)
	{
		if (*s == '$')
			handle_var(&s, &res);
		else
		{
			strcjoin(*s, &res);
			s++;
		}
	}
	strcjoin('\0', &res);
	return (res);
}

int    create_heredoc(t_redirect *rd)
{
    int     pipe_fd[2];
    char    *line;
    char    *temp;

    if (pipe(pipe_fd) == -1)
    {
        ft_putstr_fd("Error: Failed to pipe\n", 2);
        return (-1);
    }
    ft_putstr_fd(">", 0);
    while ((line = gnl(0)))
    {
        if (!(ft_strncmp(line, rd->file, ft_strlen(rd->file))))
            break ;
        temp = heredoc_expand(line);
        write(pipe_fd[1], temp, ft_strlen(temp));
        free(line);
        free(temp);
        ft_putstr_fd(">", 0);
    }
    free(line);
    close(pipe_fd[1]);
    return (pipe_fd[0]);
}
