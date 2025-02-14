/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:50:41 by ylai              #+#    #+#             */
/*   Updated: 2025/02/01 15:15:03 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int main(int argc, char **argv, char **env)
{
	// char *input;
	// should have a struct for linked list
	t_list	*env_ll;
	// t_env		key_v;
	t_attr	attr;
	// char **sample = {
	// 	"hello",
	// 	"a=1",
	// 	"b=2",
	// };

	(void)argv;
	env_ll = NULL;
	if (!check_arg(argc))
		return (0);
	setup_env(&env_ll, env);
	bi_env(&env_ll);
	setup_sig();
	init_attr(&attr);
	shell_loop(&attr);
	free_env(&env_ll);
	rl_clear_history();
	return 0;
}
