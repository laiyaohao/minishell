/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryannnaa <ryannnaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:44:28 by ylai              #+#    #+#             */
/*   Updated: 2025/03/17 15:36:00 by ryannnaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	update_attr(t_list **env_ll, t_shell *shell, char *ret)
{
	update_value(env_ll, "OLDPWD", ft_strdup(shell->attr->working_dir));
	if (shell->attr->old_working_dir)
	{
		free(shell->attr->old_working_dir);
		shell->attr->old_working_dir = ft_strdup(shell->attr->working_dir);
	}
	if (shell->attr->working_dir)
	{
		free(shell->attr->working_dir);
		shell->attr->working_dir = ft_strdup(ret);
	}
}

void	cd_err(t_shell *shell, char *path)
{
	if (errno == EACCES)
	{
		ft_putstr_fd(path, 2);
		ft_putstr_fd(" : Permission denied\n", 2);
	}
	else
	{
		ft_putstr_fd(path, 2);
		ft_putstr_fd(" : No such file or directory\n", 2);
	}
	shell->exit = 1;
}

void	change_dir_helper(t_shell *shell, t_list **env_ll, char *path)
{
	char	*ret;
	char	*tmp;
	char	cwd[4096];

	ret = NULL;
	if (chdir(path) != 0)
	{
		cd_err(shell, path);
		return ;
	}
	ret = getcwd(cwd, 4096);
	if (!ret)
	{
		ft_putstr_fd("cd: error retrieving current directory\n", 2);
		ret = ft_strjoin(shell->attr->working_dir, "/");
		tmp = ret;
		ret = ft_strjoin(tmp, path);
		free(tmp);
	}
	else
		ret = ft_strdup(cwd);
	update_attr(env_ll, shell, ret);
	update_value(env_ll, "PWD", ret);
}

void	change_dir(t_shell *shell, t_list **env_ll, char *key)
{
	char	*target_dir;

	target_dir = find_value(env_ll, key);
	if (!target_dir || target_dir[0] == '\0' || ft_isspace(target_dir[0]))
	{
		ft_putstr_fd(key, 2);
		ft_putstr_fd(" env variable have error\n", 2);
		return ;
	}
	change_dir_helper(shell, env_ll, target_dir);
}

/**
 * change the OLDPWD variable
 */
void	bi_cd(t_list **env_ll, t_shell *shell, char **args)
{
	char	*path;

	path = args[1];
	if (more_args(args, 1) || (path != NULL && !path[0]))
	{
		shell->exit = 1;
		return ;
	}
	if (!path || ft_strncmp(path, "--", 3) == 0
		|| ft_strncmp(path, "~", 2) == 0 || ft_isspace(path[0])
		|| path[0] == '\0')
	{
		change_dir(shell, env_ll, "HOME");
	}
	else if (ft_strncmp(path, "-", 2) == 0)
	{
		change_dir(shell, env_ll, "OLDPWD");
	}
	else
		change_dir_helper(shell, env_ll, path);
}
