/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:28:42 by ylai              #+#    #+#             */
/*   Updated: 2024/06/02 20:02:10 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Prints an integer to the given file descriptor.
 * @param n The integer to print.
 * @param fd The file descriptor to write to.
 * @return None.
*/
void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	n_cpy;

	if (n < 0)
	{
		n_cpy = -n;
		ft_putchar_fd('-', fd);
	}
	else
	{
		n_cpy = n;
	}
	if (n_cpy < 10)
	{
		ft_putchar_fd((n_cpy + 48), fd);
	}
	else
	{
		ft_putnbr_fd((n_cpy / 10), fd);
		ft_putnbr_fd((n_cpy % 10), fd);
	}
}
