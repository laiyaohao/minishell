/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryannnaa <ryannnaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:20:31 by tiatan            #+#    #+#             */
/*   Updated: 2025/02/28 15:43:53 by ryannnaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_redirect	*create_rd(void)
{
	t_redirect	*rd;

	rd = malloc(sizeof(t_redirect));
	if (!rd)
		return (NULL);
	ft_memset(rd, 0, sizeof(t_redirect));
	return (rd);
}

// int len_check(char *s)
// {
//     int i = 0, j = 0;
//     char quote = 0;

//     while (s[j])
//     {
//         if ((s[j] == '"' || s[j] == '\'') && !quote)
//             quote = s[j]; // Start quote mode
//         else if (s[j] == quote)
//             quote = 0; // End quote mode
//         else
//             i++;
//         j++;
//     }
//     return i;
// }

// char *remove_quotes(char *s)
// {
//     int i = 0, j = 0, len = len_check(s);
//     char *temp = malloc(len + 1);
//     char quote = 0;

//     if (!temp)
//         return NULL;

//     while (s[i])
//     {
//         if ((s[i] == '"' || s[i] == '\'') && !quote)
//             quote = s[i]; // Enter quote mode
//         else if (s[i] == quote)
//             quote = 0; // Exit quote mode
//         else
//             temp[j++] = s[i];
//         i++;
//     }
//     temp[j] = '\0';
//     return temp;
// }

// void process_args(char ***array)
// {
//     int i = 0;
//     char *temp;

//     if (!(*array))
//         return;

//     while ((*array)[i])
//     {
//         temp = remove_quotes((*array)[i]);
//         if (!temp)
//             return;
//         free((*array)[i]);
//         (*array)[i] = temp;
//         i++;
//     }
// }

int	len_check(char *s)
{
	int		i;
	int		j;
	char	quote;

	i = 0;
	j = 0;
	quote = 0;
	while (s[j])
	{
		if ((s[j] == '\'' || s[j] == '"') && !quote)
			quote = s[j];
		else if (s[j] == quote)
			quote = 0;
		else
			i++;
		j++;
	}
	return (i);
}

char	*remove_quotes(char *s)
{
	int		i;
	int		j;
	int		len;
	char	*temp;
	char	quote;

	i = 0;
	j = 0;
	quote = 0;
	len = len_check(s);
	temp = malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (NULL);
	while (s[i])
	{
		if ((s[i] == '"' || s[i] == '\'') && !quote)
			quote = s[i];
		else if (s[i] == quote)
			quote = 0;
		else
			temp[j++] = s[i];
		i++;
	}
	temp[j] = '\0';
	return (temp);
}

void	process_args(char ***array)
{
	int		i;
	char	*temp;

	if (!(*array))
		return ;
	i = 0;
	while ((*array)[i])
	{
		temp = remove_quotes((*array)[i]);
		if (!temp)
			return ;
		free((*array)[i]);
		(*array)[i] = temp;
		i++;
	}
}
