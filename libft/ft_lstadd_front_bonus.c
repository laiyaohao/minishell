/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 01:35:06 by ylai              #+#    #+#             */
/*   Updated: 2024/06/04 19:10:57 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds a new element at the beginning of a list.
 * @note If the list is empty, the new element becomes the head of the list.
 * @param lst The list to add the new element to.
 * @param new The new element to add.
 * @note If the new element is NULL, the function does nothing.
 * If the list is NULL, the function does nothing.
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst != NULL && new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}
