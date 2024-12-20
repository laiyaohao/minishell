/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:47:01 by ylai              #+#    #+#             */
/*   Updated: 2024/06/04 14:54:08 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compares two blocks of memory.
 * @param s1 The first block of memory to compare.
 * @param s2 The second block of memory to compare.
 * @param n The maximum number of bytes to compare.
 * @return 0 if the blocks of memory are equal, < 0 if s1 < s2, > 0 if s1 > s2.
 * @note The function first cast the arguments to unsigned char pointers.
 * If n is 0, the function returns 0. 
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1c;
	unsigned char	*s2c;
	size_t			i;

	i = 0;
	s1c = (unsigned char *)s1;
	s2c = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < (n - 1) && s1c[i] == s2c[i])
	{
		i++;
	}
	return (s1c[i] - s2c[i]);
}
