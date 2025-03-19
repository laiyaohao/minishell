/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:27:27 by ylai              #+#    #+#             */
/*   Updated: 2025/03/19 12:04:35 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	del_env(char **env, int i, t_list **env_ll)
{
	t_list	*node;
	t_list	*prev;

	node = *env_ll;
	if (node != NULL && ((t_env *)(node->content))->key == env[i])
	{
		*env_ll = node->next;
		free(node);
		return ;
	}
	while (node != NULL
		&& ft_strncmp(((t_env *)(node->content))->key, env[i],
		ft_strlen(((t_env *)(node->content))->key)))
	{
		prev = node;
		node = node->next;
	}
	if (node == NULL)
		return ;
	prev->next = node->next;
	free_node(node->content);
	free(node);
}
