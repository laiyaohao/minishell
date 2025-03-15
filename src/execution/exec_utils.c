/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:00:58 by tiatan            #+#    #+#             */
/*   Updated: 2025/03/15 15:09:21 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	extract_paths(t_exec *exec, t_list *env_ll)
{
	t_list	*env;
	t_env	*env_var;

	exec->paths = NULL;
	env = env_ll;
	while (env)
	{
		env_var = (t_env *)env->content;
		if (env_var && env_var->key && ft_strncmp(env_var->key, "PATH", 5) == 0)
		{
			if (env_var->value)
				exec->paths = ft_split_app(env_var->value, ':');
			break ;
		}
		env = env->next;
	}
}

void	check_path(t_exec *exec, t_ast *node)
{
	int	i;

	i = 0;
	if (exec->paths)
	{
		while (exec->paths[i])
		{
			if (node->args[0][0] != '.')
				exec->cmd = ft_strjoin(exec->paths[i], node->args[0]);
			else
				exec->cmd = ft_strdup(node->args[0]);
			if (!exec->cmd)
			{
				ft_putstr_fd("Error: Path creation issue\n", 2);
				return ;
			}
			if (access(exec->cmd, F_OK) == 0)
				break ;
			free(exec->cmd);
			exec->cmd = NULL;
			i++;
		}
	}
	if (!exec->cmd || !exec->paths)
		exec->cmd = ft_strdup(node->args[0]);
}

int	count_keys(t_list *env_ll)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = env_ll;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

char	**env_arr(t_list *env_ll)
{
	int		i;
	char	*t_value;
	char	**res;
	t_list	*temp;
	t_env	*pair;

	i = count_keys(env_ll);
	res = malloc(sizeof(char *) * (i + 1));
	if (!res)
		return (NULL);
	temp = env_ll;
	i = 0;
	while (temp)
	{
		pair = (t_env *)(temp->content);
		t_value = ft_strjoin(pair->key, "=");
		res[i] = ft_strjoin(t_value, pair->value);
		free(t_value);
		temp = temp->next;
		i++;
	}
	res[i] = NULL;
	return (res);
}
