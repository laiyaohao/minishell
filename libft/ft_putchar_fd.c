/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 21:15:12 by ylai              #+#    #+#             */
/*   Updated: 2024/06/02 20:01:17 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Writes a character to a file descriptor.
 * @param c The character to write.
 * @param fd The file descriptor to write to.
 * @return None.
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
