/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:38:43 by ylai              #+#    #+#             */
/*   Updated: 2024/06/02 19:57:03 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if a given character is printable (32-126).
 * @param c The character to check.
 * @return 1 if the character is printable, 0 otherwise.
*/
int	ft_isprint(int c)
{
	if (c <= 126 && c >= 32)
	{
		return (1);
	}
	return (0);
}
