/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:23:09 by ylai              #+#    #+#             */
/*   Updated: 2025/03/12 17:23:23 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/**
 * bi_pwd:
 *	Executes the pwd builtin command: prints the working directory.
 *	Returns 1 on completion.
 */
void	bi_pwd(void)
{
	char	*answer;

	answer = getcwd(NULL, 0);
	printf("%s\n", answer);
	free(answer);
}
