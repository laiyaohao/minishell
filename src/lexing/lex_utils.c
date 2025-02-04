#include "../../inc/minishell.h"

void	handle_pipe(char **s, int *i)
{
	*i = T_PIPE;
	(*s)++;
}

void	handle_word(char **s, int *i, char **temp)
{
	int	j;

	j = 0;
	if ((*s)[j] == '"')
	{
		j++;
		while ((*s)[j] != '"')
			j++;
		j++;
	}
	else
	{
		while ((*s)[j] != ' ' && (*s)[j])
			j++;
	}
	*i = 0;
	*temp = malloc(sizeof(char) * (j + 1));
	if (!(*temp))
		return ;
	while (*i < j)
	{
		(*temp)[*i] = (*s)[*i];
		(*i)++;
	}
	*i = T_WORD;
	(*s) += j;
}

void	handle_redir_in(char **s, int *i)
{
	(*s)++;
    if (**s == '<')
	{
		*i = T_HEREDOC;
		(*s)++;
	}
	else
		*i = T_REDIR_IN;
}

void	handle_redir_out(char **s, int *i)
{
	(*s)++;
    if (**s == '>')
	{
		*i = T_REDIR_APP;
		(*s)++;
	}
	else
		*i = T_REDIR_OUT;
}

// void	handle_var(char **s, int *i, char **temp)
// {
// 	int	j;

// 	j = 0;

// 	while ((*s)[j] != ' ' && (*s)[j])
// 		j++;
// 	*i = 0;
// 	*temp = malloc(sizeof(char) * (j + 1));
// 	if (!(*temp))
// 		return ;
// 	while (*i < j)
// 	{
// 		(*temp)[*i] = (*s)[*i];
// 		(*i)++;
// 	}
// 	*i = T_VAR;
// 	(*s) += j;
// }
