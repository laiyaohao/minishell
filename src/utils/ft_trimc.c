/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trimc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:48:46 by tiatan            #+#    #+#             */
/*   Updated: 2025/03/11 12:24:45 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*ft_trimc(char const *s1, char const *set)
{
	size_t	len;
	char	*t_set;
	size_t	i;
	size_t	j;
	size_t	size;

	len = 0;
	i = 0;
	j = 0;
	t_set = (char *)set;
	len = ft_strlen(s1);
	if (i < len && ft_strchr(t_set, s1[i]) != NULL)
		i++;
	if (j < len && ft_strrchr(t_set, s1[len - j - 1]) != NULL)
		j++;
	if (i == len && j == len)
		return (ft_substr(s1, 0, 0));
	size = len - i - j;
	return (ft_substr(s1 + i, 0, size));
}
