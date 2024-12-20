/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 21:55:25 by ylai              #+#    #+#             */
/*   Updated: 2024/06/04 16:17:04 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Applies a function to each character of a string.
 * @param s The string to apply the function to.
 * @param f The function to apply.
 * @return None.
 * @note The function first find the length of the string. using
 * ft_strlen. Then it loops through the string and apply the function `f`
 * to each character. If the string is a NULL pointer, ft_strlen will return 0. 
 * The loop will then do nothing. If the function is a NULL pointer, the
 * function will do nothing.
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;
	size_t	len;

	if (f == NULL)
		return ;
	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		f(i, s);
		s++;
		i++;
	}
}
