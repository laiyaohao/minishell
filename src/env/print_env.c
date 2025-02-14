#include "../../inc/minishell.h"

void	print_env(t_list **env_ll)
{
	t_list *list;
	t_env	*node;

	list = *env_ll;
	node = list->content;
	while (list->next != NULL)
	{
		printf("%s=", node->key);
		printf("%s\n", node->value);
		list = list->next;
		node = list->content;
	}
}
