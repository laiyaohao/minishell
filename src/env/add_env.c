#include "../../inc/minishell.h"

void	fill_key(t_env *key_v, int key_len, char *env)
{
	int i;
	char *key;

	i = 0;
	key = malloc(key_len + 1);
	while (i < key_len)
	{
		key[i] = env[i];
		i++;
	}
	key[i] = '\0';
	key_v->key = key;
}

void	fill_value(t_env *key_v, int key_len, char *env)
{
	char  *value;
	int i;
	int full_len;
	int status;

	full_len = ft_strlen(env);
	value = malloc(full_len - key_len + 1);
	i = 0;
	if (key_len > full_len)
	{
		value = NULL;
		i = -1;
	}
	while (key_len < full_len)
	{
		value[i] = env[key_len];
		key_len++;
		i++;
	}
	if (i >= 0)
		value[i] = '\0';
	key_v->value = value;
}

void	add_env(char **env, int i, t_list **env_ll)
{
	t_list  *node;
	t_env *key_v;
	char  *eq;
	int key_len;
	// int value_len;
	// t_env  *sample;

	// find first equal sign
	eq = ft_strchr(env[i], '=');
	// length of key
	key_len = eq - env[i];
	if (key_len == 0 || check_key(key_len, env[i]) || 
			check_value(key_len + 1, env[i]))
		return ;
	// value_len = ft_strchr(env[i], '\0') - eq;
	key_v = malloc(sizeof(t_env));
	fill_key(key_v, key_len, env[i]);
	fill_value(key_v, key_len + 1, env[i]);
	node = ft_lstnew(key_v);
	ft_lstadd_back(env_ll, node);
}
