/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:03:23 by ylai              #+#    #+#             */
/*   Updated: 2024/06/02 21:09:13 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Converts a lowercase character to uppercase.
 * @param c The character to convert.
 * @return The uppercase version of the character.
 * 		If the character is not a letter, it is returned unchanged.
 * 		If the character is not printable, it is returned unchanged.
 * 		Otherwise, the uppercase version of the character is returned.
 * 		Example: 'a' -> 'A'
 * 		Example: ' ' -> ' '
 * 		Example: 'z' -> 'Z'
 * 		Example: '\n' -> '\n'
 * 		Example: '\0' -> '\0'
 * 		Example: 'A' -> 'A'
 * 		Example: 'Z' -> 'Z'
*/
int	ft_toupper(int c)
{
	if (c <= 'z' && c >= 'a')
	{
		return (c - 32);
	}
	return (c);
}
