/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:22:37 by ylai              #+#    #+#             */
/*   Updated: 2025/03/12 17:22:53 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/**
 * assuming args[0] is "export"
 * if no arguments are given, need to return sorted env variables
 * if `export a=`, `a` should return empty string in both `env` 
 * and `export` commands
 * if `export a`, running export with no variables will have `a` inside,
 * but running env will not have `a` inside
 * TODO bonus: how to change the SHLVL when there is an inception of minishell
 * i.e. running minishell programme within minishell programme
 * by right, the SHLVL environment will increment by one when there is one
 * more level of inception.
 */
void	bi_export(t_list **env_ll, char **args)
{
	int	i;

	i = 1;
	if (!args[i])
	{
		print_env(env_ll, 1);
	}
	while (args[i] != NULL)
	{
		add_env(args, i, env_ll);
		i++;
	}
}
