/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:50:37 by ylai              #+#    #+#             */
/*   Updated: 2024/06/02 19:33:23 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief	Converts the initial portion of the string pointed to by nptr to an
 * 		integer.
 * @param	nptr The string to be converted. The string may begin with an
 * 		arbituary amount of white space as determined by isspace(3)
 * 		followed by an optional minus sign or plus sign. The remainder of the
 * 		string is converted to a long value in the obvious manner, stopping at
 * 		the first character which is not a valid digit in the given base.
 * @return	Returns the result of the convertion, unless the value would
 * 		underflow or overflow.  If an underflow occurs, strtol() returns LONG_MIN.
 * 		If an overflow occurs, strtol() returns LONG_MAX.
*/
int	ft_atoi(const char *nptr)
{
	long	i;
	long	ans;
	int		sign;

	i = 0;
	ans = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		ans = ans * 10 + (nptr[i] - 48);
		i++;
	}
	if (sign == -1)
		ans = ans * -1;
	return (ans);
}
