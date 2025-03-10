/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:20:34 by tiatan            #+#    #+#             */
/*   Updated: 2025/03/10 20:16:54 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	handle_quote(char **s, char **res)
{
	strcjoin(**s, res);
	(*s)++;
	while (**s && (**s) != '\'')
	{
		strcjoin(**s, res);
		(*s)++;
	}
	if (**s)
	{
		strcjoin(**s, res);
		(*s)++;
	}
}

void	handle_dquote(char **s, char **res, t_shell *shell)
{
	strcjoin(**s, res);
	(*s)++;
	while (**s && (**s) != '"')
	{
		if ((**s) == '$')
			handle_var(s, res, shell);
		else
		{
			strcjoin(**s, res);
			(*s)++;
		}
	}
	if (**s)
	{
		strcjoin(**s, res);
		(*s)++;
	}
}

char	*cmd_expand(char *s, t_shell *shell)
{
	char	*res;

	res = ft_strdup("");
	if (!res)
		return (NULL);
	while (s && *s)
	{
		if (*s == '\'')
			handle_quote(&s, &res);
		else if (*s == '"')
			handle_dquote(&s, &res, shell);
		else if (*s == '$')
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
