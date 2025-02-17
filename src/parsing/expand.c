#include "../../inc/minishell.h"

char	*handle_leading(char **s)
{
	char	*res;
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (s[i] && s[i] != '$')
	{
		i++;
		if (s[i] != '"' && s[i] != '\'')
			k++;
	}
	res = malloc(sizeof(char) * (k + 1));
	if (!res)
		return (NULL);
}

char	*handle_var(char **s)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
}

void	handle_quote(char **s, char **buffer)
{
	int	i;
	int	j;

	(*s)++;
	i = 0;
	while (s[i] && s[i] != '\'')
	{
		i++;
	}
	*buffer = malloc(sizeof(char) * (i + 1));
	if (!(*buffer))
		return ;
	j = 0;
	while (s[j] && s[j] != '\'')
	{
		buffer[j] = s[j];
		j++;
	}
	s = s + j + 1;
}

char	*handle_expand(char *s)
{
	int		state;
	int		i;
	char	*temp;
	char	*buffer;

	i = 0;
	state = 0; // 0 if to expand
	buffer = NULL;
	if (s[i] == '\'')
	{
		state = 1;
		handle_quote(&s, &buffer);
	}
	else if (s[i] == '"')
	{
		handle_dquote(&s, &state);
	}
	return (buffer);
}

// char	*expand_string(char *s)
// {
// 	char	*temp;
//     char    *var;
// 	char	*res;
// 	int		i;
// 	int		j;
// 	int		k;

//     res = handle_leading(&s);
// 	i = 0;
// 	while (s[i] && s[i] != '$')
// 	{
// 		i++;
// 		if (s[i] != '"' && s[i] != '\'')
// 			k++;
// 	}
// 	res = malloc(sizeof(char) * (k + 1));
// 	if (!res)
// 		return (NULL);
// 	k = 0;
// 	j = 0;
// 	while (k < i)
// 	{
// 		if (s[j] == '"' || s[j] == '\'')
// 			j++;
// 		if (!s[j])
// 			break ;
// 		res[k] = s[j];
// 		k++;
// 		j++;
// 	}
// 	s += i;
//     i = 0;
//     j = 0;
//     while (s)
//     {
//         if (s == '$')
//             s++;
//         while(s[i] && (ft_isalnum(s[i]) != 0 || s[i] == '_'))
//             i++;
//         temp = malloc(sizeof(char) * (i + 1));
//         if (!temp)
//             return (NULL);
//         while (j < i)
//         {
//             temp[j] = s[j];
//             j++;
//         }
//         var = getenv(temp);
//         if (!var)
//             var = ft_strdup("");
//         free(temp);
//         temp = res;
//         res = ft_strjoin(temp, var);
//         s += j;
//     }
// }