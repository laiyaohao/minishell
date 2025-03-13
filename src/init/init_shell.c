/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:06:33 by ylai              #+#    #+#             */
/*   Updated: 2025/03/13 20:43:27 by tiatan           ###   ########.fr       */
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
    shell->std_in = -1;
    shell->std_out = -1;
}
