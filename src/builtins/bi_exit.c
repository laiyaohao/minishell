/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiatan <tiatan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:45:03 by ylai              #+#    #+#             */
/*   Updated: 2025/03/15 15:13:27 by tiatan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	print_exit(t_shell *sh_atr)
{
	t_ast	*temp;
	int		check;

	check = 0;
	temp = sh_atr->tree;
	while (temp)
	{
		if (temp->type == AST_PIPE)
		{
			check = 1;
			break ;
		}
		temp = temp->right;
	}
	if (!check)
		printf("exit\n");
}

void	numeric_arg(t_shell *sh_atr, char **args)
{
	print_exit(sh_atr);
	ft_putstr_fd("bash: exit: ", 2);
	ft_putstr_fd(args[1], 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	close(sh_atr->std_in);
	close(sh_atr->std_out);
	free_every(sh_atr);
	exit(2);
}

void	byebye(t_shell *sh_atr)
{
	close(sh_atr->std_in);
	close(sh_atr->std_out);
	free_every(sh_atr);
	print_exit(sh_atr);
}

/**
 * bi_exit:
 *	Executes the exit builtin command: exits the shell with a specified
 *	exit status. If a non-numeric argument is provided, an error message
 *	is displayed and the function returns without exiting. If the argument
 *	is a number, it is converted to a long long, and the shell exits with
 *	the status obtained by taking the argument modulo 256. If no argument
 *	is given, the shell exits with status 0.
 *	@args: array of command arguments where args[0] is "exit" and args[1]
 *	is the optional exit status.
 */
void	bi_exit(t_shell *sh_atr, char **args)
{
	int	status;
	int	too_b_s;

	status = 0;
	too_b_s = 0;
	if (more_args(args, 0))
	{
		handle_non_numeric(sh_atr, args);
		print_exit(sh_atr);
		ft_putstr_fd("bash: exit: too many arguments\n", 2);
		sh_atr->exit = 1;
		return ;
	}
	else if (args != NULL && args[1] != NULL)
	{
		handle_non_numeric(sh_atr, args);
		status = ft_atoi_long(args[1], &too_b_s) % 256;
		if (status < 0)
			status = status + 256;
		if (too_b_s)
			numeric_arg(sh_atr, args);
	}
	else
		status = sh_atr->exit;
	(byebye(sh_atr), exit(status));
}
