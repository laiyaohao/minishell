/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_exit_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:04:56 by tiatan            #+#    #+#             */
/*   Updated: 2025/03/15 15:04:57 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* check_out_of_range:
*	Checks if the number goes over LONG_MAX or LONG_MIN.
*	Sets an error int to 1 if the number is out of range, 0 if not.
*/
int	check_out_of_range(int neg, unsigned long long num, int *error)
{
	if ((neg == 1 && num > LONG_MAX)
		|| (neg == -1 && num > -(unsigned long)LONG_MIN))
		*error = 1;
	return (*error);
}

/* ft_atoi_long:
*	Transforms a string comprised of digits into a long integer.
*	Returns the long integer. In case of error, sets an error int
*	to 1.
*/
int	ft_atoi_long(const char *str, int *error)
{
	unsigned long long	num;
	int					neg;
	int					i;

	num = 0;
	neg = 1;
	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		neg *= -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		num = (num * 10) + (str[i] - '0');
		if (check_out_of_range(neg, num, error))
			break ;
		i++;
	}
	return (num * neg);
}

/**
 * isdigit_str:
 *	Checks if a given string is composed only of digits.
 *	@args: string to check
 *	Returns: 0 if the string is composed only of digits, 1 otherwise
 */
int	isdigit_str(char *args)
{
	int	i;

	i = 0;
	if (args[0] == '+' || args[0] == '-')
		i++;
	while (args[i] != '\0')
	{
		if (!ft_isdigit(args[i]))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	handle_non_numeric(t_shell *sh_atr, char **args)
{
	if (isdigit_str(args[1]))
		numeric_arg(sh_atr, args);
}
