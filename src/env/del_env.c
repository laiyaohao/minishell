#include "../../inc/minishell.h"

void  del_env(char **env, int i, t_list **env_ll)
{
  // find env
  t_list  *node;
  t_list  *to_b_del;
  t_list  *fut_next;

  node = *env_ll;
  while (node->next != NULL && 
    ((t_env *)(node->next->content))->key != env[i])
  {
    node = node->next;
  }
  // now node's next is the content to be deleted.
  // find node's next's next address
  fut_next = node->next->next;
  to_b_del = node->next;
  node->next = fut_next;
  free_node(to_b_del->content);
  free(to_b_del);
}
