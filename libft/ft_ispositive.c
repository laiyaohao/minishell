/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispositive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 21:37:07 by ylai              #+#    #+#             */
/*   Updated: 2024/06/02 21:39:21 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if a given number is positive.
 * @param n The number to check.
 * @return 1 if the number is positive, 0 otherwise.
*/
int	ft_ispositive(int n)
{
	int	pos;

	if (n > 0)
	{
		pos = 1;
	}
	else
	{
		pos = 0;
	}
	return (pos);
}
