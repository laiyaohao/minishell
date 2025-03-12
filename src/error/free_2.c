/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:58:47 by tiatan            #+#    #+#             */
/*   Updated: 2025/03/12 21:01:59 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	close_rd(ast_node *tree)
{
	if (!tree)
		return ;
	close_rd(tree->left);
	close_rd(tree->right);
	if (tree->rd)
		close(tree->rd->fd);
}

void	free_shell(t_shell *shell)
{
	if (shell->env_ll)
		free_env(&shell->env_ll);
	if (shell->attr)
		free(shell->attr);
	free(shell);
}
