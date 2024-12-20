/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:53:29 by ylai              #+#    #+#             */
/*   Updated: 2024/06/04 15:50:16 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Deletes and frees the given node, and every
 *        successor of that node, using the function
 *        ’del’ and free(3).
 * @param `*lst` The node to delete.
 * @param `*del` The address of function used to delete the content of the node.
 * @return None.
 * @note The memory of ’next’ must not be freed. If the `del` function is a
 * NULL pointer, the function does nothing. Else, it applies the `del` function
 * to the content of the node, and free the memory of the node.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (del == NULL)
		return ;
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
}
