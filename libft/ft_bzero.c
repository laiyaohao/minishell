/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:49:53 by ylai              #+#    #+#             */
/*   Updated: 2024/06/02 22:03:34 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Set the first n bytes of the memory area pointed to by s to 0.
 * @param `*s` Pointer to the memory area to be set.
 * @param n Number of bytes to be set to 0.
 * @return Nothing.
 * @note This function uses the ft_memset function: ft_memset(s, 0, n)
*/
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
