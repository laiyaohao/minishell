/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 23:51:37 by ylai              #+#    #+#             */
/*   Updated: 2024/06/04 14:21:11 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief allocates memory for an array of nmemb elements of size bytes each and
 * 		returns a pointer to the allocated memory. The memory is set to zero. If
 * 		nmemb or size is 0, then calloc() returns either NULL, or a unique pointer
 * 		value that can later be successfully passed to free() (this is due to the
 * 		use of malloc(), which states that it returns NULL on error). If the
 * 		multiplication of nmemb and size would result in integer overflow, then
 * 		calloc() returns an error, which is NULL.
 * @param nmemb number of elements
 * @param size size of each element
 * @return pointer to the allocated memory, which is suitably aligned for any
 * 		built-in type. On error, these functions return NULL. NULL may also be
 * 		returned by a successful call to malloc() with a size of zero, or by a
 * 		successful call to calloc() with nmemb or size equal to zero.
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned long long	t_size;
	void				*pter;

	t_size = nmemb * size;
	if (t_size > INT_MAX)
	{
		return (NULL);
	}
	pter = (void *) malloc(t_size);
	if (pter == NULL)
	{
		return (0);
	}
	return (ft_memset(pter, 0, t_size));
}
