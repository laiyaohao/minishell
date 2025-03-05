#include "../../inc/minishell.h"

char	*ft_strdup_app(const char *s, size_t len, char c)
{
	char			*dest;
	unsigned int	i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (len + 2));
	if (dest == NULL)
		return (NULL);
	while (*(s + i) != '\0' && *(s + i) != c)
	{
		dest[i] = s[i];
		i++;
	}
	dest[len] = '/';
	dest[len + 1] = '\0';
	return (dest);
}
