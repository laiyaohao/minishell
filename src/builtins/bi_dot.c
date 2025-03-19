/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_dot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 22:17:45 by tiatan            #+#    #+#             */
/*   Updated: 2025/03/19 16:32:00 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	bi_dot(t_ast *node, t_shell *shell)
{
	ft_putstr_fd(node->args[0], 2);
	ft_putstr_fd(": filename argument required\n", 2);
	shell->exit = 2;
}
