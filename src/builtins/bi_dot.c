/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_dot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 22:17:45 by tiatan            #+#    #+#             */
/*   Updated: 2025/03/15 15:09:21 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	bi_dot(t_ast *node)
{
	ft_putstr_fd(node->args[0], 2);
	ft_putstr_fd(": filename argument required\n", 2);
}
