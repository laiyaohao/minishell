/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:17:01 by tiatan            #+#    #+#             */
/*   Updated: 2025/03/18 20:48:18 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*get_env(t_list *env_ll, char *key)
{
	t_list	*temp;
	t_env	*pair;
	char	*res;
	char	*tmp;

	temp = env_ll;
	while (temp)
	{
		pair = (t_env *)temp->content;
		if (ft_strncmp(pair->key, key, ft_strlen(key)) == 0)
		{
			if (ft_strchr(pair->value, '\'') != NULL)
			{
				tmp = ft_strjoin("\"", pair->value);
				res = ft_strjoin(tmp, "\"");
				free(tmp);
			}
			else
				res = ft_strdup(pair->value);
			return (res);
		}
		temp = temp->next;
	}
	return (NULL);
}

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
	return (temp);
}

void	handle_exit(char **s, char **res, t_shell *shell)
{
	char	*temp;
	char	*var;

	temp = *res;
	var = ft_itoa(shell->exit);
	*res = ft_strjoin(temp, var);
	free(temp);
	free(var);
	(*s)++;
}

void	var_value(char **s, char **res, t_shell *shell)
{
	char	*temp;
	char	*var;

	var = NULL;
	temp = get_var(s);
	var = get_env(shell->env_ll, temp);
	free(temp);
	temp = *res;
	if (!var)
		*res = ft_strjoin(temp, "");
	else
	{
		*res = ft_strjoin(temp, var);
	}
	if (var)
		free(var);
	if (temp)
		free(temp);
}

void	handle_var(char **s, char **res, t_shell *shell)
{
	(*s)++;
	if (!**s)
	{
		(strcjoin('$', res), strcjoin(**s, res));
		return ;
	}
	if (**s == '?')
		handle_exit(s, res, shell);
	else if (!ft_isalnum(**s) && (**s) != '_')
	{
		(strcjoin('$', res), strcjoin(**s, res));
		(*s)++;
	}
	else
		var_value(s, res, shell);
}
