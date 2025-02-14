#include "../../inc/minishell.h"

/**
 * assuming args[0] is "export"
 */
void  bi_export(t_list **env_ll, char **args)
{
  int i;

  i = 1;
  while (args[i] != NULL)
  {
    add_env(args, i, env_ll);
    i++;
  }
}
