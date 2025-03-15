/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:50:29 by tiatan            #+#    #+#             */
/*   Updated: 2025/03/14 17:50:48 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_atoll(const char *str, long long *result)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-')
		sign = -1;
	if ((*str == '-') || (*str == '+'))
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if (sign == 1 && ((num > LLONG_MAX / 10) || (num == LLONG_MAX / 10
					&& (*str - '0') > LLONG_MAX % 10)))
			return ((*result = 0), 0);
		if (sign == -1 && ((num > -(LLONG_MIN / 10)) || (num == -(LLONG_MIN
						/ 10) && (*str - '0') > -(LLONG_MIN % 10))))
			return ((*result = 0), 0);
		num = num * 10 + (*str - '0');
		str++;
	}
	*result = num * sign;
	return (1);
}
