/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:45:03 by ylai              #+#    #+#             */
/*   Updated: 2025/03/13 21:25:34 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/**
 * isdigit_str:
 *	Checks if a given string is composed only of digits.
 *	@args: string to check
 *	Returns: 0 if the string is composed only of digits, 1 otherwise
 */
int	isdigit_str(char *args)
{
	int	i;

	i = 0;
	while (args[i] != '\0')
	{
		if (!ft_isdigit(args[i]))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	numeric_arg(t_shell *sh_atr, char **args)
{
	printf("exit\n");
	printf("bash: exit: %s: numeric argument required\n", args[1]);
	free_every(sh_atr);
	exit(2);
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

	status = 0;
	if (more_args(args))
	{
		if (isdigit_str(args[1]))
			numeric_arg(sh_atr, args);
		printf("exit\n");
		printf("bash: exit: too many arguments\n");
		sh_atr->exit = 1;
		return ;
	}
	else if (args != NULL && args[1] != NULL)
	{
		if (isdigit_str(args[1]))
			numeric_arg(sh_atr, args);
		status = ft_atoi(args[1]) % 256;
		if (status < 0)
			status = status + 256;
	}
	else
		status = sh_atr->exit;
	(free_every(sh_atr), printf("exit\n"), exit(status));
}
