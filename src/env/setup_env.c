#include "../../inc/minishell.h"

void up_shlvl(t_list **env_ll)
{
	char *shlvl;

	shlvl = find_value(env_ll, "SHLVL");
	
	if (shlvl == NULL)
	{
		add_env_direct(env_ll, "SHLVL", "1");
	}
	else
	{
		shlvl = ft_itoa(ft_atoi(shlvl) + 1);
		update_value(env_ll, "SHLVL", shlvl);
	}
}

void  setup_env(t_list **env_ll, char **env)
{
	int i;
	char	*answer;

	i = 0;
	answer = NULL;
	if (env == NULL || env[i] == NULL)
	{
		// need to add SHLVL (this one may not need)
		answer = getcwd(NULL, 0);
		add_env_direct(env_ll, "_", "./minishell");
		add_env_direct(env_ll, "PWD", answer);
		free(answer);
	}
	while (env[i] != NULL)
	{
		add_env(env, i, env_ll);
		i++;
	}
	up_shlvl(env_ll);
}
