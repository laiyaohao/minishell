#include "../../inc/minishell.h"

/**
 * @brief Strip a string of any leading or trailing '\\'.
 *
 * @param line The string to strip.
 *
 * @details The function first trims the string by calling ft_strtrim,
 * then frees the original string and assigns the trimmed string to
 * the pointer.
 */
void  strip(char **line)
{
  char  *temp;

  temp = ft_strtrim(*line, "\\");
  free(*line);
  *line = ft_strdup(temp);
  free(temp);
}

/**
 * @brief Check if the last character of the input is a '\' and if the character
 * after that is not a '\0'. If it is, it means the line is not finished and
 * needs to be joined with the next input.
 *
 * @param input The string input by the user.
 *
 * @return 0 if the line is finished, 1 if it needs to be joined.
 */
int	backslash(char *input)
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

void	join(char **tbr, char **tbu)
{
	char	*temp;

	temp = ft_strdup(*tbr);
	free(*tbr);
	*tbr = ft_strjoin(temp, *tbu);
	free(temp);
}

void	line_con(t_attr *attr, char **full_line, char **input)
{
	if (attr->con_flag == 0)
	{
		free(*full_line);
		*full_line = ft_strdup(*input);
	}
	else
	{
		join(full_line, input);
		attr->con_flag = 0;
	}
}
