/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:23:34 by ylai              #+#    #+#             */
/*   Updated: 2024/06/02 19:55:29 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if a given character is alphabetic (a-z, A-Z).
 * @param c The character to check. Uses ft_islower() and ft_isupper().
 * @return 1 if the character is alphabetic, 0 otherwise.
*/
int	ft_isalpha(int c)
{
	if ((ft_islower(c)) || (ft_isupper(c)))
	{
		return (1);
	}
	return (0);
}
