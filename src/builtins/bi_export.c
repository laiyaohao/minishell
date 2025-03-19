/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:22:37 by ylai              #+#    #+#             */
/*   Updated: 2025/03/19 16:20:39 by ylai             ###   ########.fr       */
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
int	bi_export(t_list **env_ll, t_shell *shell, char **args)
{
	int	i;
	int	err;

	i = 1;
	err = 0;
	if (!args[i])
	{
		print_export(env_ll);
	}
	while (args[i] != NULL)
	{
		err = add_env(args, i, env_ll, shell);
		i++;
	}
	return (err);
}
