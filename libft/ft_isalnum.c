/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:31:23 by ylai              #+#    #+#             */
/*   Updated: 2024/06/04 19:44:29 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if a given character is alphanumeric (a-z, A-Z, 0-9).
 * 		uses ft_isalpha() and ft_isdigit().
 * @param c The character to check.
 * @return 1 if the character is alphanumeric, 0 otherwise.
*/
int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
	{
		return (1);
	}
	return (0);
}
