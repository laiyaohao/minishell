/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:59:04 by ylai              #+#    #+#             */
/*   Updated: 2025/03/12 18:59:05 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/**
 * @brief Checks if a given string represents a flag composed of 
 * a specific character.
 * 
 * This function determines whether the input string `arg` is a flag
 * that starts with a '-' character followed by one or more occurrences
 * of the character `c`. If the string matches this pattern and ends
 * without any other characters, it returns 1, indicating that the string
 * is a valid flag composed entirely of the character `c`. Otherwise,
 * it returns 0.
 * 
 * @param arg The string to check for flag pattern.
 * @param c The character that should follow the '-' in the flag.
 * @return 1 if the string is a valid flag composed of the 
 * character `c`, 0 otherwise.
 */
int	is_flag(char *arg, char c)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	if (arg[i] != '-')
		return (flag);
	i++;
	while (arg[i] && arg[i] == c)
		i++;
	if (arg[i] == '\0')
		flag = 1;
	return (flag);
}
