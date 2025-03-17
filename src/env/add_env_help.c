/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:13:32 by ylai              #+#    #+#             */
/*   Updated: 2025/03/15 21:36:55 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	add_empty_key_help(char **env, int i, t_list **env_ll)
{
	int			full_len;
	int			j;
	t_env		*key_v;
	char		*key;
	t_list		*node;

	key_v = malloc(sizeof(t_env));
	full_len = ft_strlen(env[i]);
	key = malloc(sizeof(full_len) + 1);
	j = 0;
	while (j < full_len)
	{
		key[j] = env[i][j];
		j++;
	}
	key[j] = '\0';
	key_v->key = key;
	key_v->value = NULL;
	node = ft_lstnew(key_v);
	ft_lstadd_back(env_ll, node);
}

void	add_empty_key(t_list **env_ll, char **env, char *key, int i)
{
	t_env	*temp;

	temp = find_node(env_ll, key);
	if (temp == NULL)
		add_empty_key_help(env, i, env_ll);
	free(key);
}
