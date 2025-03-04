#include "../../inc/minishell.h"

void    exec_rd(ast_node *node)
{
    if (node->rd)
        handle_redirections(node->rd);
    
}
