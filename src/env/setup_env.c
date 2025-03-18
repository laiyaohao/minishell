/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:38:46 by ylai              #+#    #+#             */
/*   Updated: 2025/03/18 15:31:25 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	up_shlvl(t_list **env_ll)
{
	char	*shlvl;
	char	*key;
	char	*value;

	shlvl = find_value(env_ll, "SHLVL");
	if (shlvl == NULL)
	{
		key = ft_strdup("SHLVL");
		value = ft_strdup("1");
		if (key && value)
			add_env_direct(env_ll, key, value);
	}
	else
	{
		shlvl = ft_itoa(ft_atoi(shlvl) + 1);
		update_value(env_ll, "SHLVL", shlvl);
	}
}

void	setup_env(t_list **env_ll, char **env, t_shell *shell)
{
	char	*answer;
	int		i;

	i = 0;
	answer = NULL;
	if (env == NULL || env[i] == NULL)
	{
		answer = getcwd(NULL, 0);
		add_env_direct(env_ll, ft_strdup("_"), ft_strdup("./minishell"));
		add_env_direct(env_ll, ft_strdup("PWD"), ft_strdup(answer));
		free(answer);
	}
	while (env[i] != NULL)
	{
		add_env(env, i, env_ll, shell);
		i++;
	}
	up_shlvl(env_ll);
}
