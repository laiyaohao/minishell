/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:38:23 by ylai              #+#    #+#             */
/*   Updated: 2024/06/04 14:25:07 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates a character in string.
 *
 * This function finds the first occurance of int `c` in string
 * `s`.
 *
 * @param s Pointer to the string s.
 * @param c Value to find. The value is passed as an int.
 * @return Returns a pointer to the first occurance of the character 'c'
 *         in the string s.
 * @note Returns NULL if the character is not found and not NULL. If the
 * 	character is NULL, it returns the pointer to the terminating null
 * 	character. The `c` being passed is first type casted into char type
 * 	before the comparison is made with every character in the string.
 */
char	*ft_strchr(const char *s, int c)
{
	char	*s1_cpy;
	char	c_typed;

	s1_cpy = (char *)s;
	c_typed = (char) c;
	while (*s)
	{
		if (*s == c_typed)
		{
			return (s1_cpy);
		}
		s1_cpy++;
		s++;
	}
	if (c_typed != 0)
	{
		return (0);
	}
	return (s1_cpy);
}
