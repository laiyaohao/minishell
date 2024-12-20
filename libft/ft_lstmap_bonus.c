/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 01:56:22 by ylai              #+#    #+#             */
/*   Updated: 2024/06/04 19:44:18 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Applies a function to each element of a list and creates a new list
 * containing the results.
 * @param lst The list to apply the function to.
 * @param f The function to apply.
 * @param del The function to free the content of the list.
 * @return A new list containing the results of the function.
 * 		If the list is NULL, NULL is returned.
 * 		If the function is NULL, NULL is returned.
 * @note The function first checks if lst or f is NULL. If either is NULL, NULL
 * is returned. A new `t_list` is initialised, then the function iterates 
 * through `lst`, applying the function `f` to the content of each node and
 * setting it to the variable `passed`. `passed` is then pass through the 
 * function `ft_lstnew`, which creates a new node and setting it ot the 
 * variable `new_node`. Since `ft_lstnew` allocates memory for the new node, 
 * if this allocation fails then, `del` is called to the `passed` variable 
 * which has the content being passed through `f`. `ft_lstclear` is then called
 * to `new_list` to clear the entire linked list. Finally, NULL is returned. 
 * If the allocation of new memory has no problems, then `ft_lstadd_back` is
 * called to add `new_node` to `new_list`. The process continues till the end 
 * of `lst` and `new_list` is returned.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*passed;

	if (lst == NULL)
		return (NULL);
	if (f == NULL)
		return (lst);
	new_list = NULL;
	while (lst)
	{
		passed = f(lst->content);
		new_node = ft_lstnew(passed);
		if (new_node == NULL)
		{
			del(passed);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
