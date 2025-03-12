#include "../../inc/minishell.h"

// void	fill_key(t_env *key_v, int key_len, char *env)
// {
// 	int i;
// 	char *key;

// 	i = 0;
// 	key = malloc(key_len + 1);
// 	while (i < key_len)
// 	{
// 		key[i] = env[i];
// 		i++;
// 	}
// 	key[i] = '\0';
// 	key_v->key = key;
// }

// void	fill_value(t_env *key_v, int val_len, char *env)
// {
// 	char  *value;
// 	int i;

// 	value = malloc(val_len + 1);
// 	i = 0;
// 	while (i < val_len)
// 	{
// 		value[i] = env[i];
// 		i++;
// 	}
// 	value[i] = '\0';
// 	key_v->value = value;
// }


void	add_empty_key_help(char **env, int i, t_list **env_ll)
{
	t_env	*key_v;
	char *key;
	int	full_len;
	int	j;
	t_list	*node;
	

	key_v = malloc(sizeof(t_env));
	full_len = ft_strlen(env[i]);
	key = malloc(sizeof(full_len) + 1);
	j = 0;
	while (j < full_len)
	{
		key[j] = env[i][j];
		j++;
	}
	key[j] = '\0';
	key_v->key = key;
	key_v->value = NULL;
	node = ft_lstnew(key_v);
	ft_lstadd_back(env_ll, node);
}

void	add_empty_key(t_list **env_ll, char **env, char *key, int i)
{
	t_env	*temp;

	temp = find_node(env_ll, key);
	if (temp == NULL)
		add_empty_key_help(env, i, env_ll);
	else
		temp->value = NULL;
	free(key);
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
	free(k);
	free(v);
}

int	find_eq(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=' && str[i] != '\0')
		i++;
	return (i);
}

void	add_env(char **env, int i, t_list **env_ll)
{
	char	*key;
	char	*value;
	char  *eq;
	int	key_len;

	eq = ft_strchr(env[i], '=');
	key_len = find_eq(env[i]);
	if (key_len == 0 || check_key(key_len, env[i]))
		return ;
	key = ft_substr(env[i], 0, key_len);
	value = ft_substr(env[i], key_len + 1, ft_strlen(env[i]) - key_len);
	if (eq == NULL)
	{
		add_empty_key(env_ll, env, key, i);
		return ;
	}
	if (check_value(key_len + 1, env[i]))
	{
		free(key);
		free(value);
		return ;
	}
	if (find_node(env_ll, key) == NULL)
		add_env_direct(env_ll, key, value);
	else
	{
		update_value(env_ll, key, value);
		free(key);
	}
}
