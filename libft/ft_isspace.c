/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:07:22 by ylai              #+#    #+#             */
/*   Updated: 2025/03/12 19:07:23 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if a given character is a whitespace character.
 * 
 * This function tests whether the input character `c` is a whitespace
 * character, which includes space, tab, newline, carriage return,
 * vertical tab, and form feed.
 * 
 * @param c The character to check.
 * @return Returns the character `c` if it is a whitespace character, 
 *         0 otherwise.
 */

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f')
		return (c);
	return (0);
}
