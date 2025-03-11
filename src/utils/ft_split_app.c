/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_app.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:24:12 by tiatan            #+#    #+#             */
/*   Updated: 2025/03/11 12:24:15 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	word_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			count++;
			while (*s != c && *s != '\0')
				s++;
		}
	}
	return (count);
}

static size_t	word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

static void	array_free(char **dest)
{
	char	**temp;

	temp = dest;
	if (temp != NULL)
	{
		while (*temp != NULL)
		{
			free(*temp);
			temp++;
		}
		free(dest);
	}
}

static char	**word_split(char const *s, char c, char **dest)
{
	size_t	len;
	int		s_count;

	s_count = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			len = word_len(s, c);
			*(dest + s_count) = ft_strdup_app(s, len, c);
			if (*(dest + s_count) == NULL)
			{
				array_free(dest);
				return (NULL);
			}
			s_count++;
			s += len;
		}
	}
	dest[s_count] = NULL;
	return (dest);
}

char	**ft_split_app(char const *s, char c)
{
	char	**dest;
	int		count;

	count = word_count(s, c);
	dest = (char **)malloc(sizeof(char *) * (count + 1));
	if (dest == NULL)
		return (NULL);
	dest = word_split(s, c, dest);
	return (dest);
}
