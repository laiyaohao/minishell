/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:06:33 by ylai              #+#    #+#             */
/*   Updated: 2025/03/12 19:06:34 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	init_shell(t_shell *shell, char **env)
{
	shell->env_ll = NULL;
	shell->attr = malloc(sizeof(t_attr));
	if (!shell->attr)
		ft_putstr_fd("Error: Failed to malloc for attr\n", 2);
	shell->tokens = NULL;
	shell->tree = NULL;
	shell->env = env;
	shell->exit = 0;
}
