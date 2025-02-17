#include "../../inc/minishell.h"

void  update_value(t_list **env_ll, char *key, char *new_v)
{
  t_env  *node;

  node = find_node(env_ll, key);
  if (node != NULL)
  {
    free(node->value);
    node->value = ft_strdup(new_v);
  }
  free(new_v);
}
