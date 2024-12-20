/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 00:46:58 by ylai              #+#    #+#             */
/*   Updated: 2024/06/04 19:09:57 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Returns the number of digits in an integer
 * @param n The integer
 * @return The number of digits
 * @note This function finds the number of digits by continuously dividng 
 * `n` by 10
*/
static int	find_len(int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

/**
 * @brief Converts an integer to a string
 * @param n The integer
 * @return The string
 * @note The function first finds the number of digits in `n`. If there 
 * are no digits, `len` is still 1. The function then checks if `n` is
 * negative. If it is, `neg` is 1. Otherwise, `neg` is 0. The function then
 * allocates memory for the string and fills it with the digits of `n`.
 * If allocation of memory fails, the function returns NULL.
 * Else, last index of ans is filled with NULL first.
 * Next, we start filling the string from the back. Create a loop of len
 * times. At each iteration, we modulo by (x + 1)'s place, find the absolute
 * value (in case `n` is negative) and x's place, where x is one's, ten's, etc.
 * Finally, if `n` is negative, we add a '-' to the front of the string.
 * Finally, we return the string.
*/
char	*ft_itoa(int n)
{
	int		len;
	int		neg;
	long	modulo;
	char	*ans;

	len = find_len(n);
	if (n == 0)
		len = 1;
	modulo = 10;
	neg = ft_isnegative(n);
	ans = (char *) malloc(sizeof(char) * (len + neg + 1));
	if (ans == NULL)
		return (NULL);
	ans[len + neg] = '\0';
	while (len--)
	{
		ans[len + neg] = ((ft_abs(n % modulo)) / (modulo / 10)) + 48;
		modulo *= 10;
	}
	if (neg)
		ans[0] = '-';
	return (ans);
}
