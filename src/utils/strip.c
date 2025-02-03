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
