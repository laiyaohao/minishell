/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnegative.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 21:03:34 by ylai              #+#    #+#             */
/*   Updated: 2024/06/02 21:07:51 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if a given number is negative.
 * @param n The number to check.
 * @return 1 if the number is negative, 0 otherwise.
*/
int	ft_isnegative(int n)
{
	int	neg;

	if (n < 0)
	{
		neg = 1;
	}
	else
	{
		neg = 0;
	}
	return (neg);
}
