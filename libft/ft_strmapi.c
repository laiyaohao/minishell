/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 21:32:24 by ylai              #+#    #+#             */
/*   Updated: 2024/06/04 15:16:43 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Applies the function f to each character of the string passed as
 *        argument, and returns a new string resulting from the successive
 *        applications of f.
 * @param s The string to apply the function to.
 * @param f The function to apply.
 * @return A pointer to the new string.
 * @note The function first checks if the function `f` applied is a NULL 
 * pointer. If the function is a NULL pointer, the
 * function will return the original string. It then finds the length
 * of the string. using ft_strlen. Then it will try to allocate memory
 * for the new string. If there is not enough memory, the function will return
 * NULL. Then it loop through the string and apply the function `f`
 * to each character. If the string is a NULL pointer, ft_strlen will return 0.
 * The new memory allocated will be one byte, and the loop will not do anything.
 * The function then adds the null terminator to the end of the new string and
 * returns it.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*ans;
	char	c_f;

	if (f == NULL)
		return ((char *) s);
	i = 0;
	len = ft_strlen(s);
	ans = (char *)malloc((len + 1) * sizeof(char));
	if (ans == NULL)
		return (NULL);
	while (i < len)
	{
		c_f = f(i, s[i]);
		ans[i] = c_f;
		i++;
	}
	ans[i] = '\0';
	return (ans);
}
