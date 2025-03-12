#include "../../inc/minishell.h"

void	if_expo(int expo)
{
	if (expo)
		printf("\"");
}

/**
 * export and env will use this function
 * export will print all env variables regardless if value
 * is NULL or not.
 * env will only print env variables that is not NULL, even
 * if it is empty string
 */
void	print_env(t_list **env_ll, int expo)
{
	t_list *list;
	t_env	*node;

	list = *env_ll;
	while (list != NULL)
	{
		node = list->content;
		if (!expo && node->value == NULL)
		{
			list = list->next;
			continue;
		}
		if (expo)
			printf("declare -x ");
		printf("%s", node->key);
		if (node->value)
		{
			printf("=");
			if_expo(expo);
			printf("%s", node->value);
			if_expo(expo);
		}
		printf("\n");
		list = list->next;
	}
}
