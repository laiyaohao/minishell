#include "../../inc/minishell.h"

void    exec_pipe(ast_node *node)
{
    int pipe_fd[2];

    if (node->type != AST_PIPE)
        exec_rd(pipe);
    if (pipe(pipe_fd) == -1)
        return ;
    exec_rd(node->left);
    exec_pipe(node->right);
}
