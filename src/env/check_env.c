/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:35:34 by ylai              #+#    #+#             */
/*   Updated: 2025/03/15 19:19:56 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_key(int key_len, char *env)
{
	int	i;
	int	err;

	i = 0;
	err = 0;
	while (i < key_len)
	{
		if (env[0] != '_' && !ft_isalpha(env[0]))
			err = 1;
		if (i != 0 && env[i] != '_' && !ft_isalnum(env[i]))
			err = 1;
		i++;
	}
	return (err);
}

// int	check_value(int key_len, char *env)
// {
// 	int	i;
// 	int	full_len;
// 	int	status;

// 	full_len = ft_strlen(env);
// 	i = 0;
// 	status = 0;
// 	while (key_len < full_len)
// 	{
// 		status = set_status(status, env, key_len);
// 		key_len++;
// 		i++;
// 	}
// 	if (status != 0)
// 		printf("Close your quotes leh\n");
// 	return (status);
// }
