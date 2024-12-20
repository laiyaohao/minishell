/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 20:33:24 by ylai              #+#    #+#             */
/*   Updated: 2024/06/04 15:09:08 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compares two strings.
 * @param s1 The first string to compare.
 * @param s2 The second string to compare.
 * @param n The maximum number of characters to compare.
 * @return 0 if the strings are equal, < 0 if s1 < s2, > 0 if s1 > s2.
 * @note If n is 0, the function returns 0.
 * If either s1 or s2 is NULL, the function returns -1.
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1u;
	unsigned char	*s2u;
	size_t			i;

	i = 0;
	s1u = (unsigned char *)s1;
	s2u = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < (n - 1) && s1u[i] == s2u[i] && s1u[i] && s2u[i])
	{
		i++;
	}
	return (s1u[i] - s2u[i]);
}
