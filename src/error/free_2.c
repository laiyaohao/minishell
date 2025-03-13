/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:58:47 by tiatan            #+#    #+#             */
/*   Updated: 2025/03/13 21:10:38 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	close_rd(ast_node *tree)
{
	t_redirect	*temp;
	
	temp = NULL;
	if (!tree)
		return ;
	close_rd(tree->left);
	close_rd(tree->right);
	if (tree->rd)
		temp = tree->rd;
	while (temp)
	{
		if (temp->fd != -1)
			close(temp->fd);
		temp = temp->next;
	}
}

void	free_shell(t_shell *shell)
{
	if (shell->env_ll)
		free_env(&shell->env_ll);
	if (shell->attr)
		free(shell->attr);
	free(shell);
}
