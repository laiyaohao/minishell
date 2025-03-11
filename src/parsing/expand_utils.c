/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:17:01 by tiatan            #+#    #+#             */
/*   Updated: 2025/03/10 21:14:43 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	handle_var(char **s, char **res, t_shell *shell)
{
	char	*temp;
	char	*var;

	var = NULL;
	(*s)++;
	if (**s == '?')
		handle_exit(s, res, shell);
	else if (!ft_isalnum(**s) && (**s) != '_')
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
