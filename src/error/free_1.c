/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:58:52 by tiatan            #+#    #+#             */
/*   Updated: 2025/03/18 16:39:22 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (temp->fd != -1)
			close(temp->fd);
		free(temp);
	}
}

void	free_ast(t_ast *node)
{
	if (!node)
		return ;
	if (node->rd)
		free_rd(node->rd);
	if (node->args)
		free_2d(node->args);
	free(node);
}

void	free_tree(t_ast *tree)
{
	if (!tree)
		return ;
	free_tree(tree->left);
	free_tree(tree->right);
	free_ast(tree);
}
