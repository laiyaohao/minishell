/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylai <ylai@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 21:39:33 by ylai              #+#    #+#             */
/*   Updated: 2024/06/04 17:17:09 by ylai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Attempts to allocate memory for an array of strings.
 * @param `**s` The allocated memory for the array of strings.
 * @param i index of the array of strings.
 * @param len The length of the string.
 * @return Either `1` or `0`. `1` if there was an error, `0` otherwise.
 * @note This functions first attempts to allocate memory of size `len + 1`
 * to `index` of s. If it fails (return NULL), a loop will traverse through
 * s and free all the allocated memory from the start of the index of the array
 * `s`. It then frees the memory of the array `s` and returns `1`.
 * If there is enough memory, it returns `0`.
*/
static int	allocate(char **s, int index, int len)
{
	int	i;

	i = 0;
	s[index] = (char *)malloc(sizeof(char) * (len + 1));
	if (s[index] == NULL)
	{
		while (i < index)
		{
			free(s[i]);
			i++;
		}
		free(s);
		return (1);
	}
	return (0);
}

/**
 * @brief Splits a string into an array of strings separated by the character
 * `c`.
 * @param `*s` The string to split.
 * @param `**ans` The allocated memory for the array of strings.
 * @param c The delimiter character.
 * @return Either `1` or `0`. `1` if there was an error, `0` otherwise.
 * @note This function is pretty similar to num_o.
 * The function first loops through the string `s` and declares a
 * variable `len` to be 0. Then it loops through the string and checks if 
 * the pointer is the same as the character `c`. If it is, it increments
 * the pointer. If it is not, it means it is inside a word. `len` is
 * incremented until it is the delimiter character. If `len` is greater
 * than 0 (i.e. there are characters in the word or 2 delimiters do not appear
 * in a row, it then calls `allocate`. If `allocate` returns `1`, it means
 * there was an error and the function returns `1`. Else, ft_strlcpy will copy
 * the word to the array of strings.
 * It will return `0` if there is no error.
*/
static int	fill(char const *s, char **ans, char c)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			len++;
			s++;
		}
		if (len)
		{
			if (allocate(ans, i, len))
				return (1);
			ft_strlcpy(ans[i], s - len, len + 1);
		}
		i++;
	}
	return (0);
}

/**
 * @brief Counts the number of words to be split according to delimiter
 * character `c`.
 * @param s The string to search.
 * @param c The delimiter character.
 * @return The number of words to be split.
 * @note This function first loops through the string `s` and checks if
 * the pointer is the same as the character `c`. If it is, it increments
 * the pointer. If it is not, it means it is inside a word. If the `inside`
 * flag is not set to true (1), then it means its the start of a new word.
 * The flag is set to true and the number of words is incremented by 1.
 * If the `inside` flag is already true, the pointer just increments.
 * The process continues until it reaches the first occurance of the character
 * is the character `c`. It resets the inside flag and the process
 * continues until the end of the string. The function finally returns the
 * number of words.
*/
static size_t	num_o(char const *s, char c)
{
	size_t	num;
	int		inside;

	num = 0;
	while (*s)
	{
		inside = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			if (inside == 0)
			{
				num++;
				inside = 1;
			}
			s++;
		}
	}
	return (num);
}

/**
 * @brief Splits a string into an array of strings seperated by the
 *        character `c`.
 * @param s The string to split.
 * @param c The character to split the string on.
 * @return An array of strings.
 * @note The function first checks if the string is a NULL pointer. If it is,
 * the function returns NULL. It then calls the function `num_o` to
 * calculate the number of words to be split. It then allocates memory
 * for the array of strings. If there is not enough memory, the function
 * returns NULL. Then it calls the function `fill` to fill the array of
 * strings. If the function returns 1, the function returns NULL.
 * Else the function returns the array of strings.
*/
char	**ft_split(char const *s, char c)
{
	char	**ans;
	int		size;

	if (s == NULL)
		return (NULL);
	size = num_o(s, c);
	ans = (char **)malloc(sizeof(char *) * (size + 1));
	if (ans == NULL)
		return (NULL);
	ans[size] = NULL;
	if (fill(s, ans, c))
	{
		return (NULL);
	}
	return (ans);
}
