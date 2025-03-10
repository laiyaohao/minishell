/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:07:13 by tiatan            #+#    #+#             */
/*   Updated: 2025/03/10 20:09:17 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/**
 * @brief Creates a token.
 *
 * @param type The token type to be recorded.
 * @param value The token's value. (NULL for all types except for T_WORD)
 *
 * @details The function creates a token with the parameters passed.
 */
t_node	*create_token(int type, char *value)
{
	t_node	*token;

	token = malloc(sizeof(t_node));
	if (!token)
	{
		ft_putstr_fd("Error: Unable to create token\n", 2);
		return (NULL);
	}
	if (value)
		token->value = ft_strdup(value);
	else
		token->value = NULL;
	token->type = type;
	token->next = NULL;
	return (token);
}

/**
 * @brief Adds a new token to a list of tokens.
 *
 * @param list List of tokens the new token is added to.
 * @param type The token type to be recorded.
 * @param value The token's value. (NULL for all types except for T_WORD)
 *
 * @details The function creates a token with the parameters passed, then
 * adds it to the end of the list.
 */
void	add_token(t_tok *list, int type, char *value)
{
	t_node	*temp;
	t_node	*token;

	token = create_token(type, value);
	if (!token)
		return ;
	if (!list->head)
		list->head = token;
	else
	{
		temp = list->head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = token;
	}
	list->count++;
}

/**
 * @brief Creates a linked list of tokens.
 *
 * @param list Pointer to where the linked list will be stored.
 * @param s String to be converted.
 *
 * @details The function iterates through the string, skipping 
 * additional spaces except for when the characters are encased
 * in a pair of "" quotes. It then identifies the character which
 * will determine what type is assigned to the token to be created.
 * After which, it will create the list of tokens to be stored.
 */
void	tokenize(t_tok *list, char *s)
{
	char	*temp;
	int		type;

	temp = NULL;
	type = 0;
	while (*s)
	{
		while (ft_isspace(*s))
			s++;
		if (*s == '|')
			handle_pipe(&s, &type);
		else if (*s == '>')
			handle_redir_out(&s, &type);
		else if (*s == '<')
			handle_redir_in(&s, &type);
		else
			handle_word(&s, &type, &temp);
		add_token(list, type, temp);
	}
	free(temp);
	temp = NULL;
	type = T_EOF;
	add_token(list, type, temp);
}

/**
 * @brief Creates a list of tokens using a string.
 *
 * @param input The string used to create the list of tokens.
 *
 * @details Tokens will be assigned with a type of the following:
 * T_WORD = "ls", "ls -l"
 * T_PIPE = "|"
 * T_REDIR_OUT = ">"
 * T_REDIR_APP = ">>"
 * T_REDIR_IN = "<"
 * T_HEREDOC = "<<"
 * T_EOF = End of token list ('\0')
 *
 * @return List of tokens if successful, NULL if failure.
 */
t_tok	*lexer(char *input)
{
	t_tok	*token_list;

	token_list = malloc(sizeof(t_tok));
	if (!token_list)
	{
		ft_putstr_fd("Error: Failed to generate Token List\n", 2);
		return (NULL);
	}
	ft_memset(token_list, 0, sizeof(t_tok));
	tokenize(token_list, input);
	return (token_list);
}

/**
 * @brief Iterates through a token list,
	and checks if there are any invalid token orders.
 *
 * @param list The list of tokens to be checked.
 *
 * @details The function checks if there are any invalid token orders.
 * This is achieved by checking that the first token is not T_PIPE,
 * and proceeds to iterate through the list and setting the state based
 * on what the encountered token type is.
 *
 * Examples of invalid token orders:
 * T_PIPE cannot be the first or last token.
 * T_WORD has no restrictions.
 * Any redirect tokens have to be followed by a T_WORD
 *
 * @return 0 if the grammar is valid, 1 if there are any errors.
 */
int	grammar_check(t_tok *list)
{
	t_node	*temp;
	int		state;

	temp = list->head;
	if (temp->type == T_PIPE)
		return (1);
	while (temp->type != T_EOF)
	{
		if (temp->type == T_WORD)
			state = 0;
		if (temp->type != T_WORD && temp->type != T_PIPE)
			state = 1;
		if (temp->type == T_PIPE)
			state = 2;
		if (state == 1 && temp->next->type != T_WORD)
			return (1);
		else if (state == 2 && (temp->next->type == T_PIPE
				|| temp->next->type == T_EOF))
			return (1);
		temp = temp->next;
	}
	return (0);
}
