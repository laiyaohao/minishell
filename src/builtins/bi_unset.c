#include "../../inc/minishell.h"

/**
 * assuming args[0] is "unset"
 */

void  bi_unset(t_list **env_ll, char **args)
{
  int i;

  i = 1;
  while (args[i] != NULL)
  {
    // if (getenv(args[i] != NULL)) // will it with variables
    // created in minishell?
    if (!check_key(ft_strlen(args[i]), args[i]))
    {
      printf("you are in\n");
      del_env(args, i, env_ll);
    }
    i++;
  }
}
