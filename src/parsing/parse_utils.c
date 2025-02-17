#include "../../inc/minishell.h"

ast_node	*create_ast_node(ast_type type)
{
	ast_node	*node;

	node = malloc(sizeof(ast_node));
	if (!node)
		return (NULL);
	node->type = type;
	node->left = NULL;
	node->right = NULL;
	node->args = NULL;
	node->rd = NULL;
	return (node);
}

int	count_args(t_node *tokens)
{
	t_node	*temp;
	int		count;

	count = 0;
	temp = tokens;
	while (temp && temp->type == T_WORD)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}
