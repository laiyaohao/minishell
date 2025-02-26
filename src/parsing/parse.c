/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:20:28 by tiatan            #+#    #+#             */
/*   Updated: 2025/02/26 18:04:37 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	parse_word(char **buffer, char *s)
{
	char	*temp;
	char	*stash;

	temp = *buffer;
	stash = handle_expand(s);
	if (!stash)
		return ;
	*buffer = ft_strjoin(temp, stash);
	if (!(*buffer))
		return ;
	free(temp);
	free(stash);
	temp = NULL;
	stash = NULL;
}

void	parse_redir(t_node **token, t_redirect **ast_rd)
{
	t_redirect	*new_rd;
	t_redirect	*last;
	char		*temp;

	new_rd = create_rd();
	new_rd->type = (*token)->type;
	(*token) = (*token)->next;
	if (new_rd->type == T_HEREDOC)
		new_rd->file = ft_strtrim((*token)->value, "'\"");
	else
	{
		temp = handle_expand((*token)->value);
		new_rd->file = ft_strtrim(temp, "'\"");
		free(temp);
	}
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
	char		*buffer;

	cmd = create_ast_node(AST_CMD);
	if (!cmd)
		return (NULL);
	buffer = ft_strdup("");
	if (!buffer)
		return (NULL);
	while ((*token) && (*token)->type != T_PIPE && (*token)->type != T_EOF)
	{
		if ((*token)->type == T_WORD)
		{
			parse_word(&buffer, (*token)->value);
			strcjoin(' ', &buffer);
		}
		else
			parse_redir(token, &cmd->rd);
		*token = (*token)->next;
	}
	cmd->args = split_args(buffer);
	free(buffer);
	process_args(&cmd->args);
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
	t_node		*start;

	start = list->head;
	tree = parse_pipe(&list->head);
	list->head = start;
	return (tree);
}

// ast_node	*parse_cmd(t_node **token)
// {
// 	ast_node	*cmd;
// 	int			count;
// 	int			i;

// 	cmd = create_ast_node(AST_CMD);
// 	if (!cmd)
// 		return (NULL);
// 	i = 0;
// 	count = count_args(*token);
// 	cmd->args = malloc(sizeof(char *) * (count + 1));
// 	if (!cmd->args)
// 		return (NULL);
// 	while ((*token) && (*token)->type != T_PIPE && (*token)->type != T_EOF)
// 	{
// 		if ((*token)->type == T_WORD)
// 		{
// 			cmd->args[i] = handle_expand((*token)->value);
// 			i++;
// 		}
// 		else
// 			parse_redir(token, &cmd->rd);
// 		*token = (*token)->next;
// 	}
// 	cmd->args[i] = NULL;
// 	return (cmd);
// }
