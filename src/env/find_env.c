#include "../../inc/minishell.h"

char  *find_value(t_list **env_ll, char *key)
{
  t_list  *list;
  t_env *node;

  list = *env_ll;
  while (list != NULL)
  {
    node = list->content;
    if (ft_strncmp(node->key, key, ft_strlen(node->key)) == 0)
    {
      return (node->value);
    }
    list = list->next;
  }
  return (NULL);
}

t_env *find_node(t_list **env_ll, char *key)
{
  t_list  *list;
  t_env *node;

  list = *env_ll;
  while (list != NULL)
  {
    node = list->content;
    if (ft_strncmp(node->key, key, ft_strlen(node->key)) == 0)
    {
      return (node);
    }
    list = list->next;
  }
  return (NULL);
}
