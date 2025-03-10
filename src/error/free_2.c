/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:58:47 by tiatan            #+#    #+#             */
/*   Updated: 2025/03/10 21:03:25 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void    free_shell(t_shell *shell)
{
    if (shell->env_ll)
        free_env(&shell->env_ll);
    if (shell->attr)
        free(shell->attr);
    free(shell);
}