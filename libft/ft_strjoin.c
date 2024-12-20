/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:20:27 by ylai              #+#    #+#             */
/*   Updated: 2024/06/04 19:31:57 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Concatenates two strings.
 * @param s1 The first string.
 * @param s2 The second string.
 * @return The concatenated string.
 * @note the function first finds the length of s1 and s2. Then, it allocates
 * 		enough memory to hold the concatenated string. If the memory allocation
 * 		fails, the function returns NULL. Otherwise, the function copies the
 * 		characters of s1 and s2 to the new string. Then the function adds the 
 * 		null terminator to the end of the string and returns it.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*space;
	size_t	i;
	size_t	s1_l;
	size_t	s2_l;

	i = -1;
	s1_l = ft_strlen(s1);
	s2_l = ft_strlen(s2);
	len = s1_l + s2_l;
	space = (char *) malloc((len + 1) * sizeof(char));
	if (space == NULL)
		return (0);
	while (++i < s1_l)
		space[i] = s1[i];
	i = -1;
	while (++i < s2_l)
		space[s1_l + i] = s2[i];
	space[len] = '\0';
	return (space);
}
