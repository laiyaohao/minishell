/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_app.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:24:06 by tiatan            #+#    #+#             */
/*   Updated: 2025/03/11 12:24:07 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*ft_strdup_app(const char *s, size_t len, char c)
{
	char			*dest;
	unsigned int	i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (len + 2));
	if (dest == NULL)
		return (NULL);
	while (*(s + i) != '\0' && *(s + i) != c)
	{
		dest[i] = s[i];
		i++;
	}
	dest[len] = '/';
	dest[len + 1] = '\0';
	return (dest);
}
