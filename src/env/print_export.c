/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:45:16 by tiatan            #+#    #+#             */
/*   Updated: 2025/03/18 20:45:17 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// Swap function to swap node contents
void	swap_env_vars(char **a, char **b)
{
	char	*temp_key;

	temp_key = *a;
	*a = *b;
	*b = temp_key;
}

void	sort_keys(char **keys, int num)
{
	int	i;
	int	j;

	if (!keys)
		return ;
	i = 0;
	while (i < num - 1)
	{
		j = 0;
		while (j < num - i - 1)
		{
			if (ft_strncmp(keys[j], keys[j + 1], ft_strlen(keys[j])) > 0)
			{
				swap_env_vars(&keys[j], &keys[j + 1]);
			}
			j++;
		}
		i++;
	}
}

// Function to print and free the sorted list
void	print_sorted_env(t_list **env_ll, char **keys, int num)
{
	int		i;
	char	*value;

	i = 0;
	while (i < num)
	{
		value = find_value(env_ll, keys[i]);
		if (value)
			printf("declare -x %s=\"%s\"\n", keys[i], value);
		else
			printf("declare -x %s\n", keys[i]);
		i++;
	}
}

int	num_keys(t_list *env_ll)
{
	int	i;

	i = 0;
	while (env_ll != NULL)
	{
		i++;
		env_ll = env_ll->next;
	}
	return (i);
}

// Function to print the sorted export list
void	print_export(t_list **env_ll)
{
	char	**keys;
	int		num;
	int		i;
	t_list	*node;

	num = num_keys(*env_ll);
	keys = malloc((num + 1) * sizeof(char *));
	i = 0;
	node = *env_ll;
	while (node != NULL)
	{
		keys[i] = ((t_env *)((node)->content))->key;
		i++;
		node = node->next;
	}
	keys[i] = NULL;
	sort_keys(keys, num);
	print_sorted_env(env_ll, keys, num);
	free(keys);
}
