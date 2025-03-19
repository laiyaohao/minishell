/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:36:05 by ylai              #+#    #+#             */
/*   Updated: 2025/03/19 12:36:49 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*find_value(t_list **env_ll, char *key)
{
	t_list		*list;
	t_env		*node;

	list = *env_ll;
	while (list != NULL)
	{
		node = list->content;
		if (ft_strncmp(node->key, key, ft_strlen(key) + 1) == 0)
		{
			return (node->value);
		}
		list = list->next;
	}
	return (NULL);
}

t_env	*find_node(t_list **env_ll, char *key)
{
	t_list		*list;
	t_env		*node;

	list = *env_ll;
	while (list != NULL)
	{
		node = list->content;
		if (ft_strncmp(node->key, key, ft_strlen(key) + 1) == 0)
		{
			return (node);
		}
		list = list->next;
	}
	return (NULL);
}
