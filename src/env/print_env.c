/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:23:53 by ylai              #+#    #+#             */
/*   Updated: 2025/03/12 16:23:54 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/**
 * export and env will use this function
 * export will print all env variables regardless if value
 * is NULL or not.
 * env will only print env variables that is not NULL, even
 * if it is empty string
 */
void	print_env(t_list **env_ll)
{
	t_list	*list;
	t_env	*node;

	list = *env_ll;
	while (list != NULL)
	{
		node = list->content;
		if (node->value == NULL)
		{
			list = list->next;
			continue ;
		}
		printf("%s", node->key);
		printf("=");
		printf("%s", node->value);
		printf("\n");
		list = list->next;
	}
}
