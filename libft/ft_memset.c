/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:45:41 by ylai              #+#    #+#             */
/*   Updated: 2024/06/04 14:22:49 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Fills a block of memory with a specified value.
 *
 * This function sets the first `n` bytes of the block of memory pointed to
 * by `s` to the specified value `c`.
 *
 * @param `*s` Pointer to the block of memory to fill.
 * @param c Value to set. The value is passed as an int, but the function
 *          fills the block of memory using the unsigned char conversion
 *          of this value.
 * @param n Number of bytes to be set to the value.
 * @return Returns the pointer to the block of memory `s`.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = (unsigned char *)s;
	while (i < n)
	{
		*p = (unsigned char)c;
		p++;
		i++;
	}
	return (s);
}
