/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:45:35 by ylai              #+#    #+#             */
/*   Updated: 2024/06/04 16:03:12 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates a character in string.
 *
 * This function finds the last occurance of int `c` in string
 * `s`.
 *
 * @param s Pointer to the string s.
 * @param c Value to find. The value is passed as an int.
 * @return Returns a pointer to the last occurance of the character 'c'
 *         in the string s.
 * @note This function first declares a variable `last_match` and sets it
 * to NULL. Then it loops through string `s`, comparing each character
 * to the character `c`. If the character is found, `last_match` is set
 * to the current character. If the character is not found, `last_match`
 * remain NULL. If `c` is NULL, the function returns the pointer to the
 * null terminator in `s`, using ft_strlen to get the length of the string
 * and adding this number to the start of the pointer of `s`, allowing
 * it to jump to the last terminaing null character.
 * Else, it will return last_match, which is the last time the character
 * was found, starting from the start of the string, conversely meaning it
 * is the first time the character was found starting from the back of the 
 * string. Since the requirement is to return NULL if the character is not
 * found, last_match is first set to NULL, so that if last_match is not
 * changed, the function will return NULL.
 */
char	*ft_strrchr(const char *s, int c)
{
	char	*last_match;

	last_match = NULL;
	while (*s)
	{
		if (*s == (char)c)
		{
			last_match = (char *)s;
		}
		s++;
	}
	if ((char)c == 0)
		return ((char *)s + ft_strlen(s));
	return (last_match);
}
