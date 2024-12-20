/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 01:47:16 by ylai              #+#    #+#             */
/*   Updated: 2024/06/04 17:26:44 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds a new element at the end of a list.
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst != NULL && new != NULL)
	{
		if (*lst != NULL)
		{
			last = ft_lstlast(*lst);
			last->next = new;
		}
		else
		{
			*lst = new;
		}
	}
}
