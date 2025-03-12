/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_every.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:59:13 by ylai              #+#    #+#             */
/*   Updated: 2025/03/12 18:59:24 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	free_every(t_shell *sh_atr)
{
	free(sh_atr->attr->full_line);
	free(sh_atr->attr->working_dir);
	free(sh_atr->attr->old_working_dir);
	free_env(&(sh_atr->env_ll));
}
