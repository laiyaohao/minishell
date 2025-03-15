/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:10:48 by ylai              #+#    #+#             */
/*   Updated: 2025/03/15 19:19:46 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	add_env_direct(t_list **env_ll, char *k, char *v)
{
	t_env		*key_v;
	t_list		*node;

	key_v = malloc(sizeof(t_env));
	fill_key(key_v, ft_strlen(k), k);
	fill_value(key_v, ft_strlen(v), v);
	node = ft_lstnew(key_v);
	ft_lstadd_back(env_ll, node);
	free(k);
	free(v);
}

int	find_eq(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=' && str[i] != '\0')
		i++;
	return (i);
}

void	env_a(char *key, char*value, t_list **env_ll)
{
	if (find_node(env_ll, key) == NULL)
		add_env_direct(env_ll, key, value);
	else
	{
		update_value(env_ll, key, value);
		free(key);
	}
}

void	add_env(char **env, int i, t_list **env_ll)
{
	char	*key;
	char	*value;
	char	*eq;
	int		key_len;

	eq = ft_strchr(env[i], '=');
	key_len = find_eq(env[i]);
	if (key_len == 0 || check_key(key_len, env[i]))
		return ;
	key = ft_substr(env[i], 0, key_len);
	value = ft_substr(env[i], key_len + 1, ft_strlen(env[i]) - key_len);
	if (eq == NULL)
	{
		(add_empty_key(env_ll, env, key, i), free(value));
		return ;
	}
	// if (check_value(key_len + 1, env[i]))
	// {
	// 	(free(key), free(value));
	// 	return ;
	// }
	env_a(key, value, env_ll);
}
