/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:44:28 by ylai              #+#    #+#             */
/*   Updated: 2025/03/12 18:56:23 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/**
 * Checks if there are more arguments than needed in the array of arguments.
 *
 * @param args The array of arguments
 * @return 1 if there are more arguments than needed, 0 otherwise
 */
int	more_args(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
		i++;
	if (i > 2)
	{
		printf("more arguments than needed.\n");
		return (1);
	}
	else
		return (0);
}

void	update_attr(t_list **env_ll, t_attr *attr, char *ret)
{
	update_value(env_ll, "OLDPWD", ft_strdup(attr->working_dir));
	if (attr->old_working_dir)
	{
		free(attr->old_working_dir);
		attr->old_working_dir = ft_strdup(attr->working_dir);
	}
	if (attr->working_dir)
	{
		free(attr->working_dir);
		attr->working_dir = ft_strdup(ret);
	}
}

void	change_dir_helper(t_attr *attr, t_list **env_ll, char *path)
{
	char	*ret;
	char	*tmp;
	char	cwd[4096];

	ret = NULL;
	if (chdir(path) != 0)
		return ;
	ret = getcwd(cwd, 4096);
	if (!ret)
	{
		printf("cd: error retrieving current directory\n");
		ret = ft_strjoin(attr->working_dir, "/");
		tmp = ret;
		ret = ft_strjoin(tmp, path);
		free(tmp);
	}
	else
		ret = ft_strdup(cwd);
	update_attr(env_ll, attr, ret);
	update_value(env_ll, "PWD", ret);
}

void	change_dir(t_attr *attr, t_list **env_ll, char *key)
{
	char	*target_dir;

	target_dir = find_value(env_ll, key);
	if (!target_dir || target_dir[0] == '\0' || ft_isspace(target_dir[0]))
	{
		printf("%s env variable have error\n", key);
		return ;
	}
	change_dir_helper(attr, env_ll, target_dir);
}

/**
 * change the OLDPWD variable
 */
void	bi_cd(t_list **env_ll, t_attr *attr, char **args)
{
	char	*path;

	path = args[1];
	if (more_args(args) || (path != NULL && !path[0]))
	{
		return ;
	}
	if (!path || ft_strncmp(path, "--", 3) == 0
		|| ft_strncmp(path, "~", 2) == 0 || ft_isspace(path[0])
		|| path[0] == '\0')
	{
		change_dir(attr, env_ll, "HOME");
	}
	else if (ft_strncmp(path, "-", 2) == 0)
	{
		change_dir(attr, env_ll, "OLDPWD");
	}
	else
		change_dir_helper(attr, env_ll, path);
}
