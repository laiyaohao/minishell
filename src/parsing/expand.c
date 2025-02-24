#include "../../inc/minishell.h"

char	*get_var(char **s)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (ft_isalnum((*s)[i]) || (*s)[i] == '_')
		i++;
	temp = malloc(sizeof(char) * (i + 1));
	if (!temp)
		return (NULL);
	j = 0;
	while (j < i)
	{
		temp[j] = (*s)[j];
		j++;
	}
	temp[j] = '\0';
	(*s) += i;
	return(temp);
}

void	handle_var(char **s, char **res)
{
	char	*temp;
	char	*var;

	var = NULL;
	(*s)++;
	if (!ft_isalnum(**s) && (**s) != '_')
	{
		strcjoin('$', res);
		strcjoin(**s, res);
		(*s)++;
	}
	else
	{
		temp = get_var(s);
		var = getenv(temp);
		free(temp);
		temp = *res;
		if (!var)
			*res = ft_strjoin(temp, "");
		else
			*res = ft_strjoin(temp, var);
		free(temp);
	}
}

void	handle_quote(char **s, char **res)
{
	(*s)++;
	while (**s && (**s) != '\'')
	{
		strcjoin(**s, res);
		(*s)++;
	}
	(*s)++;
}

void	handle_dquote(char **s, char **res)
{
	(*s)++;
	while (**s && (**s) != '"')
	{
		if ((**s) == '$')
			handle_var(s, res);
		else
			strcjoin(**s, res);
		(*s)++;
	}
	(*s)++;
}

char	*handle_expand(char *s)
{
	char	*res;

	res = ft_strdup("");
	if (!res)
		return (NULL);
	while (s && *s)
	{
		if (*s == '\'')
			handle_quote(&s, &res);
		else if (*s == '"')
			handle_dquote(&s, &res);
		else if (*s == '$')
			handle_var(&s, &res);
		else
		{
			strcjoin(*s, &res);
			s++;
		}
	}
	strcjoin('\0', &res);
	return (res);
}

//variable expansion also has to handle $? for the exit code of the last execution
//will be implemented after the signals have been integrated fully
