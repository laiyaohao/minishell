#include "../../inc/minishell.h"

void  init_attr(t_attr *attr)
{
  attr->con_flag = 0;
  attr->full_line = ft_strdup("");
}
