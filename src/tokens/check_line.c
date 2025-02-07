#include "../../inc/minishell.h"

int allowed_c(char c)
{
  if (c == 32 ||
      c == 34 ||
      c == 36 ||
      c == 39 ||
      c == 60 ||
      c == 62 ||
      c == 63 ||
      c == 124 ||
      c == 126)
      return (1);
  return (0);
}

int line_err(char *line, int i)
{
  if (ft_isalnum(line[i]) || allowed_c(line[i]))
    return (0);
  return (1);
}

int set_status(int status, char *line, int i)
{
  if (line[i] == '\'' && status == 0)
		status = 1;
	else if (line[i] == '\"' && status == 0)
		status = 1;
	else if (line[i] == '\'' && status == 1)
		status = 0;
	else if (line[i] == '\"' && status == 1)
		status = 0;
	return (status);
}

int  check_line(t_attr *attr)
{
  int i;
  int len;
  int status;

  i = 0;
  len = ft_strlen(attr->full_line);
  status = 0;
  while (i < len)
  {
    if (!line_err(attr->full_line, i))
      status = set_status(status, attr->full_line, i);
    else
    {
      status = 1;
      break;
    }
    i++;
  }
  return (status);
}
