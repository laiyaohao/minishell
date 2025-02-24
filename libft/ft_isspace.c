#include "libft.h"

/**
 * @brief Checks if a given character is a whitespace character.
 * 
 * This function tests whether the input character `c` is a whitespace
 * character, which includes space, tab, newline, carriage return,
 * vertical tab, and form feed.
 * 
 * @param c The character to check.
 * @return Returns the character `c` if it is a whitespace character, 
 *         0 otherwise.
 */

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f')
		return (c);
	return (0);
}
