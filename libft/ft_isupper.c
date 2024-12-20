/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 19:17:27 by ylai              #+#    #+#             */
/*   Updated: 2024/06/02 19:57:18 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if a given character is uppercase (A-Z).
 * @param c The character to check.
 * @return 1 if the character is uppercase, 0 otherwise.
*/
int	ft_isupper(int c)
{
	if (c <= 'Z' && c >= 'A')
	{
		return (1);
	}
	return (0);
}
