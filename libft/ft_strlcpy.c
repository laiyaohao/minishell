/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:00:58 by ylai              #+#    #+#             */
/*   Updated: 2024/06/02 20:11:31 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies at most size - 1 characters from the string src to dst,
 * including the terminating null byte ('\0').
 * @param dst The destination string.
 * @param src The source string.
 * @param size The size of the destination buffer.
 * @return The total length of the string they have in common.
 * @note The function copies at most size - 1 characters from the string src
 * to dst, including the terminating null byte ('\0').
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_l;

	i = 0;
	src_l = ft_strlen(src);
	if (size > 0)
	{
		while (i < (size - 1) && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_l);
}
