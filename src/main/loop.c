/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:22:56 by tiatan            #+#    #+#             */
/*   Updated: 2025/03/19 13:52:14 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	free_stuff(t_shell *shell)
{
	free(shell->attr->full_line);
	free(shell->attr->working_dir);
	free(shell->attr->old_working_dir);
}

void	process_input(t_shell *shell)
{
	shell->tokens = lexer(shell->attr->full_line);
	if (!shell->tokens)
		ft_putstr_fd("Failed to tokenize\n", 2);
	if (grammar_check(shell->tokens))
	{
		ft_putstr_fd("Syntax error near unexpected token\n", 2);
		shell->exit = 2;
		free_tlist(shell->tokens);
	}
	else
	{
		shell->tree = parser(shell->tokens, shell);
		debug_print_ast(shell->tree);
		shell->exit = 0;
		if (!g_sigint)
			exec_ast(shell->tree, shell);
		free_tree(shell->tree);
		free_tlist(shell->tokens);
	}
}

void	check_input(t_shell *shell)
{
	if (check_line(shell->attr))
	{
		printf("unclosed quotes: %s\n", (shell->attr->full_line));
		shell->exit = 1;
	}
	else
		process_input(shell);
	add_history((shell->attr->full_line));
}

void	shell_loop(t_shell *shell)
{
	while (1)
	{
		setup_sig_interactive();
		shell->attr->full_line = readline("minishell> ");
		if (g_sigint)
		{
			shell->exit = 130;
			g_sigint = 0;
		}
		if (!shell->attr->full_line)
		{
			write(STDOUT_FILENO, "exit\n", 6);
			break ;
		}
		if (*(shell->attr->full_line))
			check_input(shell);
		free(shell->attr->full_line);
	}
	free_stuff(shell);
}

// void	reallocate(char **tbr, char **tbu)
// {
// 	char	*temp;

// 	temp = ft_strdup(*tbr);
// 	free(*tbr);
// 	*tbr = ft_strjoin(temp, *tbu);
// 	free(temp);
// }