char    *expand_var(char *s)
{
    char    *var;
    char    buf[1000];
    char    *res;
    int     i;
    int     j;

    i = 0;
    while (s[i])
    {
        if (s[i] == '$')
            j = i;
        buf[i] = s[i];
        i++;
    }
}

char    *handle_expand(char *s)
{
    char    *temp;
    char    *res;

    if (s[0] == '\'')
    {
        temp = ft_strtrim(s, s[0]);
        res = temp;
    }
    else
    {
        if (s[0] == '"')
            temp = ft_strtrim(s, s[0]);
        res = expand_var(temp);
    }
    return (res);
}
