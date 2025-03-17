/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryannnaa <ryannnaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:06:28 by tiatan            #+#    #+#             */
/*   Updated: 2025/03/17 14:41:01 by ryannnaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	handle_pipe(char **s, int *i)
{
	*i = T_PIPE;
	(*s)++;
}

void	add_value(char **s, int *j, char **temp)
{
	int	i;

	if (*temp)
		free(*temp);
	*temp = malloc(sizeof(char) * (*j + 1));
	if (!temp)
		return ;
	i = 0;
	while (i < *j)
	{
		(*temp)[i] = (*s)[i];
		i++;
	}
	(*temp)[i] = '\0';
}

void	handle_word(char **s, int *i, char **temp)
{
	int	j;
	int	c;

	if (!s || !(*s))
		return ;
	j = 0;
	while ((*s)[j] && ft_isspace((*s)[j]) == 0)
	{
		if ((*s)[j] == '"' || (*s)[j] == '\'')
		{
			c = (*s)[j];
			j++;
			while ((*s)[j] && (*s)[j] != c)
				j++;
			j++;
		}
		else
			j++;
	}
	add_value(s, &j, temp);
	*i = T_WORD;
	if (*s)
		(*s) += j;
}

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
