/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:41:32 by ylai              #+#    #+#             */
/*   Updated: 2024/06/04 14:54:53 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies n bytes from memory area src to memory area dest.
 * @param `*dest` Destination memory area.
 * @param `*src` Source memory area.
 * @param n Number of bytes to copy.
 * @return A pointer to the destination memory area.
 * @note This function first maps src and dest to unsigned char pointers and 
 *       then checks if the start of the destination memory area
 *       is after the start of the source memory area or if memory area of the
 *       souce that is to be copied overlaps with the start of the destination
 *       memory area. If it is, it copies the source memory area to the
 *       destination memory area in reverse order. If it is not, it copies the
 *       source memory area to the destination memory area normally from
 *       the start, using the ft_memcpy function: ft_memcpy(dest, src, n).
 *       This function returns dest.
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (d > s && d < s + n)
	{
		i = n;
		while (i > 0)
		{
			d[i - 1] = s[i - 1];
			i--;
		}
	}
	else
	{
		ft_memcpy(d, s, n);
	}
	return (dest);
}
