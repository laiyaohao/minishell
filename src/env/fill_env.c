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

// void	fill_value(t_env *key_v, int key_len, char *env)
// {
// 	char  *value;
// 	int i;
// 	int full_len;

// 	full_len = ft_strlen(env);
// 	value = malloc(full_len - key_len + 1);
// 	i = 0;
// 	while (key_len < full_len)
// 	{
// 		value[i] = env[key_len];
// 		key_len++;
// 		i++;
// 	}
// 	value[i] = '\0';
// 	key_v->value = value;
// }
