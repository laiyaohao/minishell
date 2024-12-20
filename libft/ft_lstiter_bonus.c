/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 01:54:38 by ylai              #+#    #+#             */
/*   Updated: 2024/06/04 15:48:53 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Applies a function to each element of a list.
 * @param lst The list to iterate over.
 * @param f The function to apply to each element.
 * @return Nothing.
 * @note if f is NULL, the function does nothing. It then loops though the
 * linked list, applying function `f` to each node's content, before setting
 * `lst` to the address of the next node.
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (f == NULL)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
