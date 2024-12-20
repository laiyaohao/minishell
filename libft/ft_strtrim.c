/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 02:36:08 by ylai              #+#    #+#             */
/*   Updated: 2024/06/04 15:40:09 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Removes leading and trailing characters from a string.
 * @param s1 The string to trim.
 * @param set The set of characters to remove.
 * @return The trimmed string.
 * @note The function first finds the length of s1. It then iterates through
 * the string from the beginning and from the end and finds the last time the
 * character set is found in the string. That point is the start of the 
 * trimmed string. Then, it interates through the string from end to start
 * and finds the first time the character set is found in the string. That
 * point is the end of the trimmed string. If the first point reach the end
*/
char	*ft_strtrim(char const *s1, char const *set)
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
	while (i < len && ft_strchr(t_set, s1[i]) != NULL)
	{
		i++;
	}
	while (j < len && ft_strrchr(t_set, s1[len - j - 1]) != NULL)
	{
		j++;
	}
	if (i == len && j == len)
		return (ft_substr(s1, 0, 0));
	size = len - i - j;
	return (ft_substr(s1 + i, 0, size));
}
