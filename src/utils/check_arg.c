/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:58:28 by ylai              #+#    #+#             */
/*   Updated: 2025/03/13 21:39:03 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_arg(int argc)
{
	if (argc != 1)
		return (0);
	return (1);
}

/**
 * Checks if there are more arguments than needed in the array of arguments.
 *
 * @param args The array of arguments
 * @return 1 if there are more arguments than needed, 0 otherwise
 */
int	more_args(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
		i++;
	if (i > 2)
	{
		printf("more arguments than needed.\n");
		return (1);
	}
	else
		return (0);
}
