/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 20:59:03 by ylai              #+#    #+#             */
/*   Updated: 2024/06/02 21:07:46 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Returns the absolute value of a number.
 * @param num The number to get the absolute value of.
 * @return The absolute value of the number.
*/
long	ft_abs(long num)
{
	if (num < 0)
		return (-num);
	return (num);
}
