/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:18:13 by tiatan            #+#    #+#             */
/*   Updated: 2025/03/19 11:39:51 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*heredoc_expand(char *s, t_shell *shell)
{
	char	*res;

	res = ft_strdup("");
	if (!res)
		return (NULL);
	while (s && *s)
	{
		if (*s == '$')
			handle_var(&s, &res, shell);
		else
		{
			strcjoin(*s, &res);
			s++;
		}
	}
	strcjoin('\0', &res);
	return (res);
}

int	check_quote(char *s)
{
	int	i;

	i = 0;
	if (*s && *s == '$')
		i = 1;
	while (*s)
	{
		if (*s == '\'' || *s == '"')
		{
			i = 1;
			break ;
		}
		s++;
	}
	return (i);
}

void	rl_null(char *delim)
{
	ft_putstr_fd("warning: here-document at line ", 2);
	ft_putstr_fd("delimited by end-of-file (wanted `", 2);
	ft_putstr_fd(delim, 2);
	ft_putstr_fd("')\n", 2);
}
