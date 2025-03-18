/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_every.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:59:13 by ylai              #+#    #+#             */
/*   Updated: 2025/03/15 21:25:21 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	free_every(t_shell *sh_atr)
{
	if (sh_atr->env_ll)
		free_env(&(sh_atr->env_ll));
	if (sh_atr->attr)
	{
		if (sh_atr->attr->full_line)
			free(sh_atr->attr->full_line);
		if (sh_atr->attr->working_dir)
			free(sh_atr->attr->working_dir);
		if (sh_atr->attr->old_working_dir)
			free(sh_atr->attr->old_working_dir);
		free(sh_atr->attr);
	}
	if (sh_atr->tokens)
		free_tlist(sh_atr->tokens);
	if (sh_atr->tree)
		free_tree(sh_atr->tree);
	if (sh_atr->std_in != -1)
		close(sh_atr->std_in);
	if (sh_atr->std_out)
		close(sh_atr->std_out);
	free(sh_atr);
}
