#include "../../inc/minishell.h"

void	parse_redir(t_node **token, t_redirect **ast_rd)
{
	t_redirect	*new_rd;
	t_redirect	*last;

	new_rd = malloc(sizeof(t_redirect));
	if (!new_rd)
		return ;
	ft_memset(new_rd, 0, sizeof(t_redirect));
	new_rd->type = (*token)->type;
	(*token) = (*token)->next;
	new_rd->file = ft_strdup((*token)->value);
	if (!(*ast_rd))
		*ast_rd = new_rd;
	else
	{
		last = *ast_rd;
		while (last->next)
			last = last->next;
		last->next = new_rd;
	}
}

ast_node	*parse_cmd(t_node **token)
{
	ast_node	*cmd;
	int			count;
	int			i;

	cmd = create_ast_node(AST_CMD);
	if (!cmd)
		return (NULL);
	i = 0;
	count = count_args(*token);
	cmd->args = malloc(sizeof(char *) * (count + 1));
	if (!cmd->args)
		return (NULL);
	while ((*token) && (*token)->type != T_PIPE && (*token)->type != T_EOF)
	{
		if ((*token)->type == T_WORD)
		{
			cmd->args[i] = handle_expand((*token)->value);
			i++;
		}
		else
			parse_redir(token, &cmd->rd);
		*token = (*token)->next;
	}
	cmd->args[i] = NULL;
	return (cmd);
}

ast_node	*parse_pipe(t_node **token)
{
	ast_node	*left;
	ast_node	*right;
	ast_node	*pipe;

	left = parse_cmd(token);
	if (!left)
		return (NULL);
	while (*token && (*token)->type == T_PIPE)
	{
		*token = (*token)->next;
		if ((*token)->type == T_EOF)
			return (NULL);
		right = parse_pipe(token);
		if (!right)
			return (NULL);
		pipe = create_ast_node(AST_PIPE);
		pipe->left = left;
		pipe->right = right;
		left = pipe;
	}
	return (left);
}

/**
 * @brief Creates an Abstract Syntax Tree (AST) by parsing a list of tokens.
 *
 * @param list The list of tokens to be parsed.
 *
 * @details Uses recursive descent to create a structure known as the AST,
 * which will allow for execution to be done in the correct precedence.
 *
 * @return The AST if successful, NULL if failure.
 */
ast_node	*parser(t_tok *list)
{
	ast_node	*tree;

	tree = parse_pipe(&list->head);
	return (tree);
}
