/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:15:26 by tiatan            #+#    #+#             */
/*   Updated: 2025/02/25 17:40:39 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	skip_space(char **s)
{
	while (**s && ft_isspace(**s))
		(*s)++;
}

void	skip_quote(char **s, int *word, int *i)
{
	char	c;

	c = **s;
	(*s)++;
	if (!(*word))
	{
		(*i)++;
		*word = 1;
	}
	while (**s && **s != c)
		(*s)++;
	if (**s == c)
		(*s)++;
}

int	count_args(char *s)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (*s)
	{
		if (*s == '"' || *s == '\'')
			skip_quote(&s, &word, &i);
		else if (*s != ' ')
		{
			if (!word)
			{
				i++;
				word = 1;
			}
			s++;
		}
		else
		{
			word = 0;
			skip_space(&s);
		}
	}
	return (i);
}

int	word_len(char *s)
{
	char	c;
	int		i;

	i = 0;
	while (s[i] && !(ft_isspace(s[i])))
	{
		if (s[i] == '"' || s[i] == '\'')
		{
			c = s[i];
			i++;
			while (s[i] && s[i] != c)
				i++;
			if (s[i] == c)
				i++;
		}
		else
			i++;
	}
	return (i);
}

char	**split_args(char *s)
{
	char	**res;
	int		i;
	int		j;

	res = malloc(sizeof(char *) * (count_args(s) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (*s)
	{
		skip_space(&s);
		if (*s)
		{
			j = word_len(s);
			res[i] = ft_strndup(s, j);
			if (!res[i])
				return (free_2d(res), NULL);
			s += j;
			skip_space(&s);
			i++;
		}
	}
	res[i] = NULL;
	return (res);
}
