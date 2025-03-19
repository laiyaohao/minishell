/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:30:58 by tiatan            #+#    #+#             */
/*   Updated: 2025/03/19 15:31:21 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*affix_quote(char *s)
{
	char	*res;

	res = ft_strdup("");
	if (!res)
		return (NULL);
	while (*s)
	{
		if (*s && (*s == '\'' || *s == '"'))
		{
			strcjoin(Q_MARKER, &res);
			strcjoin(*s, &res);
			s++;
		}
		else
		{
			strcjoin(*s, &res);
			s++;
		}
	}
	return (res);
}

int	check_quotes(char *s)
{
	if (ft_strchr(s, '"') != NULL | ft_strchr(s, '\'') != NULL)
		return (1);
	return (0);
}
