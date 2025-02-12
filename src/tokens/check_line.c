#include "../../inc/minishell.h"

int not_allowed(char c)
{
  if (c == 59 || // semicolon
      c == 92 || // backslash
      c == 96) // backtick
    return (1);
  return (0);
}

int line_err(char *line, int i)
{
  if (not_allowed(line[i]))
    return (1);
  return (0);
}

int set_status(int status, char *line, int i)
{
  if (line[i] == '\'' && status == 0)
		status = 1;
	else if (line[i] == '\"' && status == 0)
		status = 2;
	else if (line[i] == '\'' && status == 1)
		status = 0;
	else if (line[i] == '\"' && status == 2)
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
    status = set_status(status, attr->full_line, i);
    if (status == 0 && line_err(attr->full_line, i))
    {
      status = 1;
      break;
    }
    i++;
  }
  return (status);
}
