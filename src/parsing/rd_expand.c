#include "../../inc/minishell.h"

void	rd_quote(char **s, char **res)
{
	(*s)++;
	while (**s && **s != '\'')
	{
		strcjoin(**s, res);
		(*s)++;
	}
	if (**s && **s == '\'')
		(*s)++;
}

void	rd_dquote(char **s, char **res)
{
	(*s)++;
	while (**s && **s != '"')
	{
		if ((**s) == '$')
			handle_var(s, res);
		else
		{
			strcjoin(**s, res);
			(*s)++;
		}
	}
	if (**s == '"')
		(*s)++;
}
void	hd_dquote(char **s, char **res)
{
	(*s)++;
	while (**s && **s != '"')
	{
		{
			strcjoin(**s, res);
			(*s)++;
		}
	}
	if (**s && **s == '"')
		(*s)++;
}

char	*rd_expand(char *s, int mode)
{
	char	*res;

	res = ft_strdup("");
	if (!res)
		return (NULL);
	while (s && *s)
	{
		if (*s == '\'')
			rd_quote(&s, &res);
		else if (*s == '"' && !mode)
            hd_dquote(&s, &res);
        else if (*s == '"' && mode)
			rd_dquote(&s, &res);
		else if (*s == '$' && mode)
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
