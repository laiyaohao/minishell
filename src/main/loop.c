/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:22:56 by tiatan            #+#    #+#             */
/*   Updated: 2025/03/12 16:09:20 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	process_input(t_shell *shell)
{
	shell->tokens = lexer(shell->attr->full_line);
	if (!shell->tokens)
		ft_putstr_fd("Failed to tokenize\n", 2);
	if (grammar_check(shell->tokens))
		ft_putstr_fd("Syntax error near unexpected token\n", 2);
	else
	{
		shell->tree = parser(shell->tokens, shell);
		exec_ast(shell->tree, shell);
		free_tree(shell->tree);
		free_tlist(shell->tokens);
	}
}

void	shell_loop(t_shell *shell)
{
	while (1)
	{
		shell->attr->full_line = readline("minishell> ");
		if (!shell->attr->full_line)
			break ;
		if (*(shell->attr->full_line))
		{
			if (check_line(shell->attr))
				printf("have error lah deh: %s\n", (shell->attr->full_line));
			else
				process_input(shell);
			add_history((shell->attr->full_line));
		}
		free(shell->attr->full_line);
	}
	free(shell->attr->full_line);
	free(shell->attr->working_dir);
	free(shell->attr->old_working_dir);
}

// void	reallocate(char **tbr, char **tbu)
// {
// 	char	*temp;

// 	temp = ft_strdup(*tbr);
// 	free(*tbr);
// 	*tbr = ft_strjoin(temp, *tbu);
// 	free(temp);
// }