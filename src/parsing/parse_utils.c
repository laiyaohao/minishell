/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:20:31 by tiatan            #+#    #+#             */
/*   Updated: 2025/02/25 17:20:41 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

ast_node	*create_ast_node(ast_type type)
{
	ast_node	*node;

	node = malloc(sizeof(ast_node));
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
	return (rd);
}

int	len_check(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] == '\'' || s[j] == '"')
		{
			j++;
		}
		else
		{
			j++;
			i++;
		}
	}
	return (i);
}

char	*remove_quotes(char *s)
{
	int		i;
	int		j;
	int		len;
	char	*temp;

	i = 0;
	j = 0;
	len = len_check(s);
	temp = malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (NULL);
	while (s[i])
	{
		if (s[i] == '"' || s[i] == '\'')
			i++;
		else
		{
			temp[j] = s[i];
			i++;
			j++;
		}
	}
	temp[j] = '\0';
	return (temp);
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
