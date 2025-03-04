#include "../../inc/minishell.h"

void  setup_env(t_list **env_ll, char **env)
{
  int i;

  i = 0;
  while (env[i] != NULL)
  {
    add_env(env, i, env_ll);
    i++;
  }
  // t_env  *sample = (*env_ll)->content;
  // printf("key: %s\n", sample->key);
  // printf("value: %s\n", sample->value);
}
