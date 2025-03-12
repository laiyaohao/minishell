/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:37:56 by ylai              #+#    #+#             */
/*   Updated: 2025/03/12 16:45:03 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	free_node(t_env *node)
{
	free(node->key);
	free(node->value);
	free(node);
}

void	free_env(t_list **env_ll)
{
	t_list		*list;
	t_list		*next;
	t_env		*node;

	list = *env_ll;
	node = list->content;
	while (list->next != NULL)
	{
		next = list->next;
		free_node(node);
		free(list);
		list = next;
		node = list->content;
	}
	free_node(node);
	free(list);
}
