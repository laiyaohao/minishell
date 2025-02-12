#include "../../inc/minishell.h"

void  pwd(t_astnode *node, t_shelly *shell)
{
  (void)node;
  (void)shell;
  char  *answer;

  answer = getcwd(NULL, 0);
  printf("%s\n", answer);
  free(answer);
}
