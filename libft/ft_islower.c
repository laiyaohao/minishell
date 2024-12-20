/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 19:16:35 by ylai              #+#    #+#             */
/*   Updated: 2024/06/04 17:19:44 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if a given character is lowercase (a-z).
 * @param c The character to check.
 * @return 1 if the character is lowercase, 0 otherwise.
*/
int	ft_islower(int c)
{
	if (c <= 'z' && c >= 'a')
	{
		return (1);
	}
	return (0);
}
