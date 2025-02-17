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
    // next_n = next->content;
		// printf("key: %s\n", node->key);
		// printf("value: %s\n", node->value);
    free_node(node);
    free(list);
    list = next;
		node = list->content;
	}
  // free(*env_ll);
  free_node(node);
  free(list);
}