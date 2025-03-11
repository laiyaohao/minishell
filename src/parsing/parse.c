/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:20:28 by tiatan            #+#    #+#             */
/*   Updated: 2025/03/10 20:49:55 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/**
 * @brief Processes the value of the word token and concatenates it with the
 * buffer.
 *
 * @param buffer The buffer whereby expanded word tokens' values are stored.
 * @param s The value of the token.
 *
 * @details The functions takes the value of a word token and expands it if
 * required. It then concatenates the buffer with the newly expanded word.
 */
void	parse_word(char **buffer, char *s, t_shell *shell)
{
	char	*temp;
	char	*stash;

	temp = *buffer;
	stash = cmd_expand(s, shell);
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

/**
 * @brief Creates a redirection node and appends it to the back of the
 * list of redirections.
 *
 * @param token The address of the token to be parsed.
 * @param ast_rd The list of redirections the new node is to be appended to.
 *
 * @details The function creates a redirect node by copying the type of the
 * token, then processing the token after as the delimiter for heredoc
 * or the file for all other redirections.
 */
void	parse_redir(t_node **token, t_redirect **ast_rd, t_shell *shell)
{
	t_redirect	*new_rd;
	t_redirect	*last;
	int			mode;

	new_rd = create_rd();
	new_rd->type = (*token)->type;
	(*token) = (*token)->next;
	if (new_rd->type == T_HEREDOC)
	{
		mode = check_quote((*token)->value);
		new_rd->file = rd_expand((*token)->value, 0, shell);
		new_rd->fd = create_heredoc(new_rd->file, shell, mode);
	}
	else
		new_rd->file = rd_expand((*token)->value, 1, shell);
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

/**
 * @brief Creates a command AST node.
 *
 * @param token The address of the token to be parsed.
 *
 * @details The function iterates through the token list processing all word
 * and redirection tokens to construct the arguments of the command node and
 * the linked list of redirections for the command node.
 *
 * @return A command AST node. NULL if failure.
 */
ast_node	*parse_cmd(t_node **token, t_shell *shell)
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
			parse_word(&buffer, (*token)->value, shell);
			strcjoin(' ', &buffer);
		}
		else
			parse_redir(token, &cmd->rd, shell);
		*token = (*token)->next;
	}
	cmd->args = split_args(buffer);
	free(buffer);
	process_args(&cmd->args);
	return (cmd);
}

/**
 * @brief Creates a pipe AST node via recursive descent.
 *
 * @param token The address of the token to be parsed.
 *
 * @details A recursive descent parser uses recursion to call upon itself till
 * it reaches the base case. The tokens can be interpreted and constructed as
 * one of the following: pipe node, command node, redirection.
 * 
 * The function parses the token as a command. If a pipe token is present in
 * the list of tokens to be parsed, a pipe node will be created and the command
 * node created will be appended to the left of the pipe node while it calls upon
 * itself to construct the node to be appended to the right pointer.
 *
 * @return A pipe AST node if a pipe token is present in the list,
 * else a command AST node. NULL if failure.
 */
ast_node	*parse_pipe(t_node **token, t_shell *shell)
{
	ast_node	*left;
	ast_node	*right;
	ast_node	*pipe;

	left = parse_cmd(token, shell);
	if (!left)
		return (NULL);
	while (*token && (*token)->type == T_PIPE)
	{
		*token = (*token)->next;
		if ((*token)->type == T_EOF)
			return (NULL);
		right = parse_pipe(token, shell);
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
 * @brief Creates an Abstract Syntax Tree (AST) via parsing.
 *
 * @param list The list of tokens to be parsed.
 *
 * @details Creates the AST by calling on the parse_pipe function which will
 * recursively parse the list of tokens.
 * 
 * Keeps a pointer to the orignal head of the list of tokens, so that it can
 * be freed later.
 *
 * @return The AST if successful, NULL if failure.
 */
ast_node	*parser(t_tok *list, t_shell *shell)
{
	ast_node	*tree;
	t_node		*start;

	tree = NULL;
	start = list->head;
	tree = parse_pipe(&list->head, shell);
	if (!tree)
		ft_putstr_fd("Error: Failed to create AST\n", 2);
	list->head = start;
	return (tree);
}
