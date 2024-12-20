/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 19:22:51 by ylai              #+#    #+#             */
/*   Updated: 2024/06/05 15:28:11 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Finds the first occurrence of a substring in a string.
 * @param big The string to search in.
 * @param little The substring to search for.
 * @param len The maximum length of the substring to search for.
 * @return The address of the first occurrence of the substring in the string.
 * 		If the substring is not found, it returns NULL.
 * @note The functions first find the length of `big` and `little` using
 * ft_strlen. If little's length is 0 (i.e little is a NULL pointer), the
 * function returns the pointer to the start of the string `big`. A loop will
 * then traverse through the string `big` and find the first time it is the first
 * character of the substring `little`. If it is fonud, it then starts the second
 * loop to check if the rest of the substring `little` is in the string `big`
 * sequantially. If it is found, it returns the address of the first character
 * of the first occurance of `little` is found. If the first occurance of the
 * matching character is not found, it returns NULL.
 * Even if `big` is an empty string, the loop will do nothing and it will
 * return NULL.
*/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*big_cp;
	size_t	i;
	size_t	j;
	size_t	l_l;
	size_t	b_l;

	i = 0;
	big_cp = (char *)big;
	l_l = ft_strlen(little);
	b_l = ft_strlen(big);
	if (l_l == 0)
		return (big_cp);
	while (i < len && i < b_l)
	{
		j = 0;
		if (big_cp[i] == little[j])
		{
			while (big_cp[i + j] == little[j] && j < l_l && (i + j) < len)
				j++;
			if (j == l_l)
				return (big_cp + i);
		}
		i++;
	}
	return (0);
}
