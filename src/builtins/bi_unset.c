/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:17:00 by ylai              #+#    #+#             */
/*   Updated: 2025/03/19 16:13:51 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/**
 * assuming args[0] is "unset"
 */

int	bi_unset(t_list **env_ll, char **args)
{
	int	i;
	int	err;

	i = 1;
	err = 0;
	while (args[i] != NULL)
	{
		if (!check_key(ft_strlen(args[i]), args[i]))
		{
			err = del_env(args, i, env_ll);
		}
		i++;
	}
	return (err);
}
