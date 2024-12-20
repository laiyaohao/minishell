/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:46:04 by ylai              #+#    #+#             */
/*   Updated: 2024/06/02 20:13:17 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Returns the length of a string.
 * @param str The string to get the length of.
 * @return The length of the string.
 * @note This function returns 0 if the string is NULL.
 * @note This function returns 0 if the string is empty.
 * @note This function returns 1 if the string is a single character.
 * @note This function returns the length of the string if it is longer than 1.
*/
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}
