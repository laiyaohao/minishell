/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:15:26 by tiatan            #+#    #+#             */
/*   Updated: 2025/02/25 16:16:10 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	count_args(char *s)
{
	int		i;
	int		word;
	char	c;

	i = 0;
	word = 0;
	while (*s)
	{
		if (*s == '"' || *s == '\'')
		{
			c = *s;
			s++;
			if (!word)
			{
				i++;
				word = 1;
			}
			while (*s && *s != c)
				s++;
			if (*s == c)
				s++;
		}
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
			while (*s == ' ')
				s++;
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
	int		k;

	i = count_args(s);
	res = malloc(sizeof(char *) * (i + 1));
	if (!res)
		return (NULL);
	j = 0;
	while (*s)
	{
		while (ft_isspace(*s))
			s++;
		if (*s)
		{
			k = word_len(s);
			res[j] = ft_strndup(s, k);
			if (!res[j])
			{
				free_2d(res);
				return (NULL);
			}
			s += k;
			while (ft_isspace(*s))
				s++;
			j++;
		}
	}
	res[j] = NULL;
	return (res);
}
