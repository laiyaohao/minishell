#include "../../inc/minishell.h"

int    create_heredoc(void)
{
    int pipe_fd[2];

    if (pipe(pipe_fd) == -1)
        ft_putstr_fd("Error: Failed to pipe\n", 2);
    return (0);
}
