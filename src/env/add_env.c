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

void	fill_value(t_env *key_v, int val_len, char *env)
{
	char  *value;
	int i;
	// int full_len;

	// full_len = ft_strlen(env);
	value = malloc(val_len + 1);
	i = 0;
	while (i < val_len)
	{
		value[i] = env[i];
		i++;
	}
	value[i] = '\0';
	key_v->value = value;
}

void	add_empty_key(char **env, int i, t_list **env_ll)
{
	t_env	*key_v;
	char *key;
	int	full_len;
	int	j;
	t_list	*node;
	

	key_v = malloc(sizeof(t_env));
	full_len = ft_strlen(env[i]);
	key = malloc(sizeof(full_len));
	j = 0;
	while (j < full_len)
	{
		key[j] = env[i][j];
		j++;
	}
	key_v->key = key;
	key_v->value = NULL;
	node = ft_lstnew(key_v);
	ft_lstadd_back(env_ll, node);
}

void	add_env_direct(t_list **env_ll, char *k, char *v)
{
	t_env *key_v;
	t_list  *node;

	key_v = malloc(sizeof(t_env));
	fill_key(key_v, ft_strlen(k), k);
	fill_value(key_v, ft_strlen(v), v);
	node = ft_lstnew(key_v);
	ft_lstadd_back(env_ll, node);
}

void	add_env(char **env, int i, t_list **env_ll)
{
	t_list  *node;
	t_env *key_v;
	char  *eq;
	int key_len;
	int  val_len;

	// find first equal sign
	eq = ft_strchr(env[i], '='); // will be NULL if not found
	// i.e. export VAR
	if (eq == NULL)
	{
		add_empty_key(env, i, env_ll);
		return ;
	}
	// length of key
	key_len = eq - env[i];
	if (key_len == 0 || check_key(key_len, env[i]) || 
			check_value(key_len + 1, env[i]))
		return ;
	val_len = ft_strlen(env[i]) - key_len;
	key_v = malloc(sizeof(t_env));
	fill_key(key_v, key_len, env[i]);
	fill_value(key_v, val_len, env[i] + key_len + 1);
	node = ft_lstnew(key_v);
	ft_lstadd_back(env_ll, node);
}
