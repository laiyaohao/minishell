/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:56:04 by ylai              #+#    #+#             */
/*   Updated: 2024/06/04 19:12:28 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Deletes and frees the given element and every successor of that
 * element, using ft_lstdelone, which uses the function ’del’ and free(3).
 * @param lst The list to clear.
 * @param del The function used to delete the content of the list.
 * @note If the list is NULL, the function does nothing.
 * If the function `del` is a NULL pointer, the function does nothing.
*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*cur;

	if (del == NULL)
		return ;
	if (lst && *lst)
	{
		cur = *lst;
		while (cur)
		{
			temp = cur;
			cur = cur->next;
			ft_lstdelone(temp, del);
		}
		*lst = NULL;
	}
}
