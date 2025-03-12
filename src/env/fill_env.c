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
