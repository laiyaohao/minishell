/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:05:16 by tiatan            #+#    #+#             */
/*   Updated: 2025/03/19 15:06:06 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	handle_redir_in(char **s, int *i)
{
	(*s)++;
	if (**s == '<')
	{
		*i = T_HEREDOC;
		(*s)++;
	}
	else
		*i = T_REDIR_IN;
}

void	handle_redir_out(char **s, int *i)
{
	(*s)++;
	if (**s == '>')
	{
		*i = T_REDIR_APP;
		(*s)++;
	}
	else
		*i = T_REDIR_OUT;
}

void	handle_pipe(char **s, int *i)
{
	*i = T_PIPE;
	(*s)++;
}
