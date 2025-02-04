#include "../../inc/minishell.h"

int ft_isspace(int c)
{
    return (c == '\t' || c == '\r' || c == '\n' || c == '\v' || c == '\f' || c == ' ');
}
