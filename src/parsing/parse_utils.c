/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:20:31 by tiatan            #+#    #+#             */
/*   Updated: 2025/03/19 15:34:21 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_ast	*create_t_ast(t_ast_type type)
{
	t_ast	*node;

	node = malloc(sizeof(t_ast));
	if (!node)
		return (NULL);
	node->type = type;
	node->left = NULL;
	node->right = NULL;
	node->args = NULL;
	node->rd = NULL;
	return (node);
}

t_redirect	*create_rd(void)
{
	t_redirect	*rd;

	rd = malloc(sizeof(t_redirect));
	if (!rd)
		return (NULL);
	ft_memset(rd, 0, sizeof(t_redirect));
	rd->fd = -1;
	return (rd);
}

void	nested_quotes(char **s, char **res)
{
	int	c;

	c = **s;
	(*s)++;
	while (**s && **s != c)
	{
		if (**s && **s == Q_MARKER)
		{
			(*s)++;
			strcjoin(**s, res);
			(*s)++;
		}
		else
		{
			strcjoin(**s, res);
			(*s)++;
		}
	}
	(*s)++;
}

char	*remove_quotes(char *s)
{
	char	*res;

	res = ft_strdup("");
	if (!res)
		return (NULL);
	while (*s)
	{
		if (*s && *s == Q_MARKER)
		{
			s++;
			strcjoin(*s, &res);
			s++;
		}
		else if (*s && (*s == '"' || *s == '\''))
		{
			nested_quotes(&s, &res);
		}
		else
		{
			strcjoin(*s, &res);
			s++;
		}
	}
	return (res);
}

void	process_args(char ***array)
{
	int		i;
	char	*temp;

	if (!(*array))
		return ;
	i = 0;
	while ((*array)[i])
	{
		temp = remove_quotes((*array)[i]);
		if (!temp)
			return ;
		free((*array)[i]);
		(*array)[i] = temp;
		i++;
	}
}
