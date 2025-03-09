#include "../../inc/minishell.h"

void  free_node(t_env *node)
{
  free(node->key);
  free(node->value);
  free(node);
}

void  free_env(t_list **env_ll)
{
	t_list *list;
	t_env	*node;
  t_list  *next;
  // t_env  *next_n;

	list = *env_ll;
	node = list->content;
	while (list->next != NULL)
	{
		next = list->next;
    free_node(node);
    free(list);
    list = next;
		node = list->content;
	}
  free_node(node);
  free(list);
}
