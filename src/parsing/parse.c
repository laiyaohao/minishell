#include "../../inc/minishell.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*ans;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	ans = (char *) malloc((len + 1) * sizeof(char));
	if (ans == NULL)
		return (NULL);
	while (i < len)
	{
		ans[i] = s[i];
		i++;
	}
	ans[i] = '\0';
	return (ans);
}

t_cmd   *parse_cmd(t_node *token, int count)
{
    t_cmd   *cmd;
    int     i;

    if (token->type != T_WORD)
        return (NULL);
    cmd = malloc(sizeof(t_cmd));
    if (!cmd)
        return (NULL);
    ft_memset(cmd, 0, sizeof(cmd));
    i = 0;
    cmd->args = malloc(sizeof(char *) * count);
    if (!(cmd->args))
        return (NULL);
    while (token->type == T_WORD)
    {
        cmd->args[i] = ft_strdup(token->value);
        i++;
        token = token->next;
    }
    cmd->args[i] = NULL;
    return (cmd);
}

t_cmd   *parse_redir(t_node *token, int count)
{
    t_cmd   *cmd;
    cmd = parse_cmd(token, count);
    if (!cmd)
        return (NULL);
    if (token->type == T_HEREDOC)
    {
        token = token->next;
        // heredoc(token);
    }
    else if (token->type == T_REDIR_IN)
    {
        token = token->next;
        cmd->in_fd = open(token->value, O_RDONLY);
    }
    else if(token->type == T_REDIR_OUT)
    {
        token = token->next;
        cmd->out_fd = open(token->value, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    }
    else
    {
        token = token->next;
        cmd->out_fd = open(token->value, O_CREAT | O_WRONLY | O_APPEND, 0644);
    }
    token = token->next;
    return (cmd);
}

t_cmd   *parse_pipe(t_node *token, int count)
{
    t_cmd   *left;
    t_cmd   *right;

    left = parse_redir(token, count);
    if (!left)
        return (NULL);
    while (token->type == T_PIPE)
    {
        token = token->next;
        right = parse_redir(token, count);
        left->next = right;
        left = right;
    }
    return(left);
}

/**
 * @brief Creates an Abstract Syntax Tree (AST) by parsing a list of tokens.
 *
 * @param list The list of tokens to be parsed.
 *
 * @details 
 * 
 * @return The AST if successful, NULL if failure.
 */
t_cmd    *parser(t_tok *list)
{
    t_cmd   *tree;

    tree = parse_pipe(list->head, list->count);
    return (tree);
}
