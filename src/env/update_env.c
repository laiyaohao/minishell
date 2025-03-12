/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:35:43 by ylai              #+#    #+#             */
/*   Updated: 2025/03/12 16:35:57 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	update_value(t_list **env_ll, char *key, char *new_v)
{
	t_env	*node;

	node = find_node(env_ll, key);
	if (node != NULL)
	{
		free(node->value);
		node->value = ft_strdup(new_v);
	}
	free(new_v);
}
