#include "../../inc/minishell.h"

ast_node	*create_ast_node(ast_type type)
{
	ast_node	*node;

	node = malloc(sizeof(ast_node));
	if (!node)
		return (NULL);
	node->type = type;
	node->left = NULL;
	node->right = NULL;
	node->args = NULL;
	node->rd = NULL;
	return (node);
}

void	remove_quotes(char ***array)
{
	int		i;
	int		j;
	int		k;
	char	*temp;

	if (!(*array))
		return ;
	i = 0;
	while ((*array)[i])
	{
		j = 0;
		k = 0;
		while ((*array)[i][j])
		{
			if ((*array)[i][j] == '\'' || (*array)[i][j] == '"')
			{
				j++;
			}
			else
			{
				j++;
				k++;
			}
		}
		temp = malloc(sizeof(char) * (k + 1));
		if (!temp)
			return ;
		j = 0;
		k = 0;
		while ((*array)[i][j])
		{
			if ((*array)[i][j] == '"' || (*array)[i][j] == '\'')
				j++;
			else
			{
				temp[k] = (*array)[i][j];
				k++;
				j++;
			}
		}
		temp[k] = '\0';
		free((*array)[i]);
		(*array)[i] = temp;
		i++;
	}
	
}

