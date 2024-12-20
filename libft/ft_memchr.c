/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 20:19:51 by ylai              #+#    #+#             */
/*   Updated: 2024/06/04 19:19:45 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief scans the initial n bytes of the memory area pointed to by s for the
 * first instance of c. Both c and the bytes of the memory area pointed to by s
 * are interpreted as unsigned char
 * @param s pointer to the memory area to be scanned
 * @param c character to search for
 * @param n number of bytes to be scanned
 * @return a pointer to the byte located, or NULL if the character is not found
 * @note The function first casts the arguments to unsigned char pointers. If
 * n is 0, the function returns NULL. If either s or c is NULL, the function
 * returns NULL. Otherwise, the function returns a pointer to the first byte
 * located. If c is not found, the function returns NULL.
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	c1;
	size_t			i;
	void			*s_cp;

	i = 0;
	s_cp = (void *)s;
	s1 = (unsigned char *)s;
	c1 = (unsigned char)c;
	while (i < n)
	{
		if (*s1 == c1)
		{
			return (s_cp);
		}
		i++;
		s_cp++;
		s1++;
	}
	return (0);
}
