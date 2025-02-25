#include "../../inc/minishell.h"

void	strcjoin(char s, char **res)
{
	int		len;
	char	*temp;

	if (!(*res))
		len = 0;
	else
		len = ft_strlen(*res);
	temp = malloc(sizeof(char) * (len + 2));
	if (!temp)
		return ;
	len = 0;
	while ((*res)[len])
	{
		temp[len] = (*res)[len];
		len++;
	}
	temp[len] = s;
	temp[len + 1] = '\0';
	free(*res);
	*res = temp;
}