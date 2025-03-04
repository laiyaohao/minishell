#include "../../inc/minishell.h"

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
	if (!attr->working_dir)
	{
		printf("no space to strdup working dir\n");
		return ;
	}
	if (find_value(env_ll, "OLDPWD") != NULL)
	{
		attr->old_working_dir = ft_strdup(find_value(env_ll, "OLDPWD"));
		if (!attr->old_working_dir)
		{
			printf("no space to strdup OLDPWD\n");
			return ;
		}
	}
	else
	{
		attr->old_working_dir = ft_strdup(wd);
		if (!attr->old_working_dir)
		{
			printf("no space to strdup working dir\n");
			return ;
		}
	}
}

void  init_attr(t_attr *attr, t_list **env_ll)
{
	attr->full_line = NULL;
	init_wds(attr, env_ll);
}
