/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:54:06 by ylai              #+#    #+#             */
/*   Updated: 2024/06/04 19:14:36 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Creates and returns a new node
 * @param content The content of the new node
 * @return The new node
 * @note The function first allocates memory using the malloc() function
 * to create a new node. If the memory allocation fails, the function returns
 * NULL. Otherwise,  the function sets the content of the new node to
 * `content` and the `next` pointer of the new node to NULL. Finally, the
 * function returns the new node.
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*ans;

	ans = (t_list *)malloc(sizeof(t_list));
	if (ans == NULL)
		return (NULL);
	ans->content = content;
	ans->next = NULL;
	return (ans);
}
