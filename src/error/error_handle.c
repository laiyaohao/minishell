#include "../../inc/minishell.h"

void	free_2d(char **memory)
{
	size_t	i;

	i = 0;
	while (memory[i])
	{
		free(memory[i]);
		i++;
	}
	free(memory);
	memory = NULL;
}

void	free_tlist(t_tok *tokens)
{
	t_node	*temp;

	while (tokens->head)
	{
		temp = tokens->head;
		if (temp->value)
			free(temp->value);
		tokens->head = tokens->head->next;
		free(temp);
	}
	free(tokens);
}

void	free_rd(t_redirect *rd)
{
	t_redirect	*temp;

	while (rd)
	{
		temp = rd;
		rd = rd->next;
		free(temp->file);
		if (temp->fd != 0)
			close(temp->fd);
		free(temp);
	}
}

void	free_ast(ast_node *node)
{
	if (!node)
		return ;
	if (node->rd)
		free_rd(node->rd);
	if (node->args)
		free_2d(node->args);
	free(node);
}

void	free_tree(ast_node *tree)
{
	if (!tree)
		return ;
	free_tree(tree->left);
	free_tree(tree->right);
	free_ast(tree);
}
