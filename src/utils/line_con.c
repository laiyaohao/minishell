#include "../../inc/minishell.h"

/**
 * @brief Check if the last character of the input is a '\' and if the character
 * after that is not a '\0'. If it is, it means the line is not finished and
 * needs to be joined with the next input.
 *
 * @param input The string input by the user.
 *
 * @return 0 if the line is finished, 1 if it needs to be joined.
 */
int	line_con(char *input)
{
	char	*temp;

	temp = ft_strchr(input, 92);
	if (!temp || *(temp + 1) != '\0')
	{
		return (0);
	}
	else
		return (1);
}
