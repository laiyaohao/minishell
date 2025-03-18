/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryannnaa <ryannnaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 19:07:44 by ylai              #+#    #+#             */
/*   Updated: 2025/03/17 14:20:47 by ryannnaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	print_no_space(char *dir)
{
	if (!dir)
	{
		printf("no space\n");
		return ;
	}
}

/* init_wds:
*	Initializes working directory variables as a safeguard against
*	environment PWD and OLDPWD being unset or otherwise not present
*	in the environment. Used for cd builtin.
*	Returns true if successful, false in case of error.
*/
void	init_wds(t_attr *attr, t_list **env_ll)
{
	char	buff[4096];
	char	*wd;

	wd = getcwd(buff, 4096);
	attr->working_dir = ft_strdup(wd);
	print_no_space(attr->working_dir);
	if (find_value(env_ll, "OLDPWD") != NULL)
	{
		attr->old_working_dir = ft_strdup(find_value(env_ll, "OLDPWD"));
		print_no_space(attr->old_working_dir);
	}
	else
	{
		attr->old_working_dir = ft_strdup(wd);
		print_no_space(attr->old_working_dir);
	}
}

void	init_attr(t_attr *attr, t_list **env_ll)
{
	attr->full_line = NULL;
	init_wds(attr, env_ll);
}
