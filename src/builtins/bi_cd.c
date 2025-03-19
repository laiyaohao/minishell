/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:44:28 by ylai              #+#    #+#             */
/*   Updated: 2025/03/19 16:44:04 by ylai             ###   ########.fr       */
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

int	change_dir_helper(t_shell *shell, t_list **env_ll, char *path)
{
	char	*ret;
	char	*tmp;
	char	cwd[4096];

	ret = NULL;
	if (chdir(path) != 0)
	{
		cd_err(shell, path);
		return (1);
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
	return (EXIT_SUCCESS);
}

int	change_dir(t_shell *shell, t_list **env_ll, char *key)
{
	char	*target_dir;

	target_dir = find_value(env_ll, key);
	if (!target_dir || target_dir[0] == '\0' || ft_isspace(target_dir[0]))
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(key, 2);
		ft_putstr_fd(" not set\n", 2);
		shell->exit = 1;
		return (1);
	}
	return (change_dir_helper(shell, env_ll, target_dir));
}

/**
 * change the OLDPWD variable
 */
int	bi_cd(t_list **env_ll, t_shell *shell, char **args)
{
	char	*path;
	char	*home;
	int		err;

	path = args[1];
	err = 0;
	if (more_args(args, 1) || (path != NULL && !path[0]))
		return (1);
	if (!path || ft_strncmp(path, "--", 3) == 0
		|| ft_strncmp(path, "~", 2) == 0 || path[0] == '\0')
		return (change_dir(shell, env_ll, "HOME"));
	else if (ft_strncmp(path, "-", 2) == 0)
		return (change_dir(shell, env_ll, "OLDPWD"));
	else if (ft_strncmp(path, "~", 1) == 0)
	{
		home = find_value(env_ll, "HOME");
		if (home)
			path = ft_strjoin(home, args[1] + 1);
		else
			path = ft_strdup(args[1]);
		err = change_dir_helper(shell, env_ll, path);
		return (free(path), err);
	}
	else
		return (change_dir_helper(shell, env_ll, path));
}
