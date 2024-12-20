/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:09:36 by ylai              #+#    #+#             */
/*   Updated: 2024/06/02 20:57:06 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Converts a character to lowercase.
 * @param c The character to convert.
 * @return The lowercase version of the character.
 * 		If the character is not a letter, it is returned unchanged.
 * 		If the character is not printable, it is returned unchanged.
 * 		Otherwise, the lowercase version of the character is returned.
 * 		Example: 'A' -> 'a'
 * 		Example: ' ' -> ' '
 * 		Example: 'Z' -> 'z'
 * 		Example: '\n' -> '\n'
 * 		Example: '\0' -> '\0'
*/
int	ft_tolower(int c)
{
	if (c <= 'Z' && c >= 'A')
	{
		return (c + 32);
	}
	return (c);
}
