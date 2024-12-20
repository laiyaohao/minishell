/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 01:43:11 by ylai              #+#    #+#             */
/*   Updated: 2024/06/04 19:33:21 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Returns the last element of a list.
 * @param lst The list to get the last element from.
 * @return The last element of the list.
 * @note If the list is empty, NULL is returned.
 * @note If the list contains only one element, that element is returned.
 * @note If the list contains multiple elements, the last element 
 * 		is returned
 * @note the function iterates though `lst` making sure that the `next` pointer
 * is not NULL. Then the `lst` is reset to the address of the `next` pointer.
 * If `next` is NULL, this means that the current node is the last node in the
 * list. In this case, `lst` is returned.
*/
t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
